#include <stdio.h>

#define ERROR 0
#define OK 1

typedef struct {
    int visibility;
    int allow_notification;
    int refresh_rate;
    int region;
    int font_size;
} Settings;

void PrintSettings(Settings *settings) {
    printf("Visibility: %d\n", settings->visibility);
    printf("AllowNotification: %d\n", settings->allow_notification);
    printf("RefreshRate: %d\n", settings->refresh_rate);
    printf("Region: %d\n", settings->region);
    printf("FontSize: %d\n", settings->font_size);
}

int SaveSettings(Settings *settings, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(&settings->visibility, sizeof(int), 1, file);
        fwrite(&settings->allow_notification, sizeof(int), 1, file);
        fwrite(&settings->refresh_rate, sizeof(int), 1, file);
        fwrite(&settings->region, sizeof(int), 1, file);
        fwrite(&settings->font_size, sizeof(int), 1, file);
        fclose(file);
        return OK;
    } else {
        return ERROR;
    }
}

int SaveSettings2(Settings *settings, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(settings, sizeof(Settings), 1, file);
        fclose(file);
        return OK;
    } else {
        return ERROR;
    }
}

void LoadSettings(Settings *settings, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(&settings->visibility, sizeof(int), 1, file);
        fread(&settings->allow_notification, sizeof(int), 1, file);
        fread(&settings->refresh_rate, sizeof(int), 1, file);
        fread(&settings->region, sizeof(int), 1, file);
        fread(&settings->font_size, sizeof(int), 1, file);
        fclose(file);
    } else {
        settings->visibility = 0;
        settings->allow_notification = 0;
        settings->refresh_rate = 0;
        settings->region = 0;
        settings->font_size = 0;
    }
}

void LoadSettings2(Settings *settings, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(settings, sizeof(Settings), 1, file);
        fclose(file);
    } else {
        settings->visibility = 0;
        settings->allow_notification = 0;
        settings->refresh_rate = 0;
        settings->region = 0;
        settings->font_size = 0;
    }
}

int main() {
    Settings settings = {11, 22, 33, 44, 55};
    SaveSettings(&settings, "settings.bin");
    PrintSettings(&settings);

    Settings settings2;
    LoadSettings(&settings2, "settings.bin");
    PrintSettings(&settings2);

    Settings settings3 = {1, 2, 3, 4, 5};
    SaveSettings2(&settings3, "settings.bin");
    PrintSettings(&settings3);

    Settings settings4;
    LoadSettings2(&settings4, "settings.bin");
    PrintSettings(&settings4);

    return 0;
}
