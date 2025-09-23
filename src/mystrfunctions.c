#include "../include/mystrfunctions.h"
#include <stdio.h>

int mystrlen(const char* s) {
    if (!s) return -1;
    int len = 0;
    while (s[len]) len++;
    return len;
}

int mystrcpy(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;
}

int mystrncpy(char* dest, const char* src, int n) {
    if (!dest || !src || n <= 0) return -1;
    int i = 0;
    for (i = 0; i < n - 1 && src[i]; i++) dest[i] = src[i];
    dest[i] = '\0';
    return i;
}

int mystrcat(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int dlen = mystrlen(dest);
    int i = 0;
    while (src[i]) {
        dest[dlen + i] = src[i];
        i++;
    }
    dest[dlen + i] = '\0';
    return dlen + i;
}
