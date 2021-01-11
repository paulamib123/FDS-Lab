#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;
    char ch;

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    fp3 = fopen(argv[3], "w");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        printf("\n Could not open files!");
    }

    ch = fgetc(fp1);
    while (ch != EOF) {
        fputc(ch, fp3);
        ch = fgetc(fp1);
    }

    ch = fgetc(fp2);
    while (ch != EOF) {
        fputc(ch, fp3);
        ch = fgetc(fp2);
    }

    printf("\n Successfully merged two files!");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("\n");
    return 0;
}
