#include "../include/myfilefunctions.h"
#include <stdlib.h>
#include <string.h>

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;

    *lines = *words = *chars = 0;
    int c, inWord = 0;

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if (c == ' ' || c == '\n' || c == '\t') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            (*words)++;
        }
    }
    rewind(file);
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;

    char buffer[1024];
    int count = 0;
    int capacity = 10;
    *matches = malloc(capacity * sizeof(char*));
    if (!*matches) return -1;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, search_str)) {
            if (count >= capacity) {
                capacity *= 2;
                char** temp = realloc(*matches, capacity * sizeof(char*));
                if (!temp) return -1;
                *matches = temp;
            }
            (*matches)[count] = strdup(buffer);
            count++;
        }
    }
    rewind(fp);
    return count;
}
