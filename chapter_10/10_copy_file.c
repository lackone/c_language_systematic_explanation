#include <stdio.h>

#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENT -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -6

int copyFile(const char *src, const char *dst) {
    if (!src || !dst) {
        return COPY_ILLEGAL_ARGUMENT;
    }
    FILE *srcFile = fopen(src, "r");
    if (!srcFile) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *dstFile = fopen(dst, "w");
    if (!dstFile) {
        fclose(srcFile);
        return COPY_DEST_OPEN_ERROR;
    }
    int ret;
    while (1) {
        int c = fgetc(srcFile);
        if (c == EOF) {
            if (ferror(srcFile)) {
                ret = COPY_SRC_READ_ERROR;
            } else if (feof(srcFile)) {
                ret = COPY_SUCCESS;
            } else {
                ret = COPY_UNKNOWN_ERROR;
            }
            break;
        }
        if (fputc(c, dstFile) == EOF) {
            ret = COPY_DEST_WRITE_ERROR;
            break;
        }
    }
    fclose(srcFile);
    fclose(dstFile);
    return ret;
}

int main() {
    printf("%d\n", copyFile("test.txt", "test2.txt"));

    return 0;
}
