#include <string.h>

int lengthOfLastWord(char* s) {
    int l = strlen(s) - 1;
    int k = 0;

    // skip trailing spaces
    while (l >= 0 && s[l] == ' ')
        l--;

    // count the last word
    while (l >= 0 && s[l] != ' ') {
        k++;
        l--;
    }

    return k;
}