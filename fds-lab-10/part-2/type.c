#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE * fp;
    char ch;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
        printf("Could not open file!");

    ch = fgetc(fp);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fp);
    }

    printf("\n");
    fclose(fp);

    return 0;
}