#include <stdio.h>

typedef enum FileFormat {
    PNG,
    JPEG,
    BMP,
    UNKNOWN
} FileFormat;

FileFormat getFileFormat(const char *filename) {
    FILE *file = fopen(filename, "rb");
    FileFormat file_format = UNKNOWN;
    if (file) {
        char buffer[8] = {0};
        size_t bytes_count = fread(buffer, 1, 8, file);
        if (bytes_count == 8) {
            //bmp 42 4d
            //png 89 50 4e 47 0d 0a 1a 0a
            //jpeg ff d8 ff e0
            if (*(short *) buffer == 0x4d42) {
                file_format = BMP;
            } else if (*(long long *) buffer == 0x0A1A0A0D474E5089) {
                file_format = PNG;
            } else if (*(int *) buffer == 0xE0FFD8FF) {
                file_format = JPEG;
            }
        }
        fclose(file);
    }
    return file_format;
}

int main() {
    FileFormat f = UNKNOWN;


    return 0;
}
