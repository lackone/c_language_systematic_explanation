#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

typedef struct Context {
    mtx_t mtx;
    int download_left;
} Context;

typedef struct DownloadRequest {
    Context *context;
    char const *url;
    char const *filename;
    int progress;
    int interval;

    void (*callback)(struct DownloadRequest *);
} DownloadRequest;

int DownloadFile(DownloadRequest *request) {
    printf("Download file from %s into %s ...\n", request->url, request->filename);

    for (int i = 0; i <= 100; i++) {
        request->progress = i;
        thrd_sleep(&(struct timespec){.tv_nsec = 1000000}, NULL);
    }

    request->callback(request);

    return 0;
}

void DownloadCallback(DownloadRequest *request) {
    mtx_lock(&request->context->mtx);
    request->context->download_left--;
    printf("Download file from %s into %s left: %d.\n", request->url, request->filename,
           request->context->download_left);
    mtx_unlock(&request->context->mtx);
}

int main() {
    char *urls[] = {
        "http://www.google.com/1",
        "http://www.google.com/2",
        "http://www.google.com/3",
        "http://www.google.com/4",
        "http://www.google.com/5",
    };

    char *filenames[] = {
        "download1.jpg",
        "download2.jpg",
        "download3.jpg",
        "download4.jpg",
        "download5.jpg",
    };

    DownloadRequest request[5];

    Context context = {.download_left = 5};

    mtx_init(&context.mtx, mtx_plain);

    for (int i = 0; i < 5; i++) {
        request[i] = (DownloadRequest){
            .context = &context,
            .url = urls[i],
            .filename = filenames[i],
            .progress = 0,
            .interval = i * 50 + 100,
            .callback = DownloadCallback,
        };

        thrd_t t;
        thrd_create(&t, DownloadFile, &request[i]);
        thrd_detach(t);
    }

    while (1) {
        mtx_lock(&context.mtx);
        int left = context.download_left;
        mtx_unlock(&context.mtx);
        if (left == 0) {
            break;
        }
        printf("\r");
        for (int i = 0; i < 5; i++) {
            printf("%s -- %3d%% \t", request[i].url, request[i].progress);
        }

        fflush(stdout);
        thrd_sleep(&(struct timespec){.tv_nsec = 1000000}, NULL);
    }

    mtx_destroy(&context.mtx);

    return 0;
}
