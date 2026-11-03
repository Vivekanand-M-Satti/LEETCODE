#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc(n + 1);
    int k = 0;                      // write position in res

    int i = n - 1;
    while (i >= 0) {
        // skip spaces
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) break;

        // find the word s[j+1..i]
        int end = i;
        while (i >= 0 && s[i] != ' ') i--;
        int start = i + 1;

        // add a separator before every word except the first
        if (k != 0) res[k++] = ' ';

        // copy the word forward
        for (int j = start; j <= end; j++) {
            res[k++] = s[j];
        }
    }

    res[k] = '\0';
    return res;
}