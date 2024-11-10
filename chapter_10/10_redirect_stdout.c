#include <stdio.h>

#if defined(__unix__) || defined(__APPLE__) || defined(__linux__)
#include <unistd.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <io.h>
#endif

void redirectStdout(char *fileName) {
    static int save_stdout = -1;
    if (fileName) {
        if (save_stdout == -1) {
            save_stdout = dup(fileno(stdout));
        }
        fflush(stdout);
        freopen(fileName, "a", stdout);
    } else {
        if (save_stdout != -1) {
            fflush(stdout);
            dup2(save_stdout, fileno(stdout));
            close(save_stdout);
            save_stdout = -1;
        }
    }
}

//dup(int fildes)
//dup2(int fildes, int fildes2)
int main() {
    //freopen("output.log", "a", stdout);
    //puts("test test");
    //fclose(stdout);

    puts("1");
    redirectStdout("output.log");
    puts("2");
    redirectStdout(NULL);
    puts("3");
    redirectStdout("output.log");
    puts("4");
    redirectStdout(NULL);
    puts("END");

    return 0;
}
