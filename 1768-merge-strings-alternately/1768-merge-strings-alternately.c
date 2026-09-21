#include <stdlib.h>

char* mergeAlternately(char* word1, char* word2) {

    char *result = (char *)malloc(201 * sizeof(char));

    int i = 0;
    int j = 0;
    int k = 0;

    // Take characters alternately while both strings have characters
    while (word1[i] != '\0' && word2[j] != '\0') {

        result[k] = word1[i];
        k++;
        i++;

        result[k] = word2[j];
        k++;
        j++;
    }

    // Add remaining characters of word1
    while (word1[i] != '\0') {
        result[k] = word1[i];
        k++;
        i++;
    }

    // Add remaining characters of word2
    while (word2[j] != '\0') {
        result[k] = word2[j];
        k++;
        j++;
    }

    // End the C string
    result[k] = '\0';

    return result;
}