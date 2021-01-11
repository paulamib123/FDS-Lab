#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char new_name[100];

    printf("\n Old file name is: %s", argv[1]);
    printf("\n Enter new file name: ");
    scanf("%s", new_name);

    if (rename(argv[1], new_name) == 0) {
        printf("\nFiles Renamed Successfully!");
    }
    else {
        printf("\nUnable to rename files");
    }
    printf("\n");
    
    return 0;
}