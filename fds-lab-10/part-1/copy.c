#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE* source_file;
    FILE* destination_file;
    char ch;

    source_file = fopen(argv[1], "r");
    destination_file = fopen(argv[2], "w");

    if (source_file == NULL || destination_file == NULL) {
        printf("\n Unable to open File");
    }

    ch = fgetc(source_file);
    while (ch != EOF) {
        fputc(ch, destination_file);
        ch = fgetc(source_file);
    }

    printf("\nFiles Copied Successfully");
    printf("\n");

    fclose(source_file);
    fclose(destination_file);

    return 0;
}