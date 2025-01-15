#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc == 1) {
        printf("0");
        return 0;
    } 

    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    printf("%d", sum);

    return 0;
}
