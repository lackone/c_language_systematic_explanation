#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

//获取文件大小
long getFileSize(char *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

int isDir(char *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_mode & S_IFDIR;
}

int main() {
    //文件删除
    int ret = remove("test3.txt");
    printf("%d\n", ret);

    ret = remove("test3.txt");
    printf("%d\n", ret);

    //重命名
    ret = rename("test2.txt", "test222.txt");
    printf("%d\n", ret);

    //获取一个临时文件
    FILE *file = tmpfile();
    printf("%s\n", file->_tmpfname);
    fclose(file);

    printf("%ld\n", getFileSize("test4.txt"));

    printf("%ld\n", isDir("test4.txt"));

    printf("%ld\n", isDir("./"));

    return 0;
}
