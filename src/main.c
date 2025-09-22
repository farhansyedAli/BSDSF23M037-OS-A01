#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    char str1[50] = "Hello";
    char str2[50];

    printf("Length of '%s': %d\n", str1, mystrlen(str1));

    mystrcpy(str2, str1);
    printf("Copied string: %s\n", str2);

    mystrncpy(str2, "World!", 3);
    printf("After strncpy (3 chars): %s\n", str2);

    mystrcat(str1, " World");
    printf("After strcat: %s\n", str1);

    printf("\n--- Testing File Functions ---\n");
    FILE* file = fopen("test.txt", "r");
    if (file) {
        int lines, words, chars;
        if (wordCount(file, &lines, &words, &chars) == 0) {
            printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, chars);
        }

        char** matches;
        int found = mygrep(file, "test", &matches);
        if (found > 0) {
            printf("Found %d matching lines:\n", found);
            for (int i = 0; i < found; i++) {
                printf("%s", matches[i]);
                free(matches[i]);
            }
            free(matches);
        }
        fclose(file);
    } else {
        printf("Could not open test.txt for file function tests.\n");
    }

    return 0;
}
