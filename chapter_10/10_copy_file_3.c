#include <stdio.h>

#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENT -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -6
#define BUFFER_SIZE 1024

int copyFile(const char *src, const char *dst) {
    if (!src || !dst) {
        return COPY_ILLEGAL_ARGUMENT;
    }
    FILE *srcFile = fopen(src, "rb");
    if (!srcFile) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *dstFile = fopen(dst, "wb");
    if (!dstFile) {
        fclose(srcFile);
        return COPY_DEST_OPEN_ERROR;
    }
    int ret = COPY_SUCCESS;

    char buf[BUFFER_SIZE];
    while (1) {
        size_t bytes_read = fread(buf, 1, BUFFER_SIZE, srcFile);
        if (fwrite(buf, 1, bytes_read, dstFile) < bytes_read) {
            ret = COPY_DEST_WRITE_ERROR;
            break;
        }

        if (bytes_read < BUFFER_SIZE) {
            if (ferror(srcFile)) {
                ret = COPY_SRC_READ_ERROR;
            } else if (feof(srcFile)) {
                ret = COPY_SUCCESS;
            } else {
                ret = COPY_UNKNOWN_ERROR;
            }
            break;
        }
    }

    fclose(srcFile);
    fclose(dstFile);
    return ret;
}

int main() {
    printf("%d\n", copyFile("test.txt", "test4.txt"));

    return 0;
}
