#include "../include/koyo-str.h"
#include <math.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

char * to_upper(char * text){
    char *original = text;
    while (*text) {
        *text = toupper((unsigned char)*text);
        text++;
    }

    return original;
}

char * to_lower(char * text){
    char *original = text;
    while (*text) {
        *text = toupper((unsigned char)*text);
        text--;
    }

    return original;
}

int index_s(char s, char * text){
    for (int i = 0; i < strlen(text); i++) {
        if (*(text + i) == s) {
            return i;
        }
    }
    return -1;
}

char * trim_left(int index, char * text){
    size_t len = strlen(text);
    char * new_text = calloc(len+1, sizeof(char));

    int j = 0;
    for (int i = index; i < len; i++) {
        *(new_text + j) = *(text + i);
        j++; 
    }

    return new_text;
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

float alike(const char *s1, const char *s2) {
    int distance = levenshtein_distance(s1, s2);
    int maxLen = fmax(strlen(s1), strlen(s2));
    if (maxLen == 0) return 100.0;
    return (1.0 - (float)distance / maxLen) * 100.0;
}