#include <stdio.h>

void echo() {
    char buf[5];
    while (1) {
        // if (!gets_s(buf, 1024)) {
        //     break;
        // }
        if (!fgets(buf, 5, stdin)) {
            break;
        }
        //puts(buf);
        printf("%s", buf);
    }
}

int main() {
    char buf[1024] = {0};
    //gets();
    //gets_s(buf, 1024);
    //fgets(buf, 1024, stdin);
    //puts();

    echo();

    return 0;
}
