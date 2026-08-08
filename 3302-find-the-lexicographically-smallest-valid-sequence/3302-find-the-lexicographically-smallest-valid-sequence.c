

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* validSequence(char* word1, char* word2, int* returnSize) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);

    int* dp2 = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n2; i++) {
        dp2[i] = -1;
    }

    int j = n2 - 1;

    for (int i = n1 - 1; i >= 0; i--) {
        if (j >= 0 && word1[i] == word2[j]) {
            dp2[j] = i;
            j--;
        }
    }

    int* res = (int*)malloc(n2 * sizeof(int));
    int resSize = 0;

    int changed = 0;
    j = 0;

    for (int i = 0; i < n1; i++) {
        if (j >= n2) {
            break;
        }

        if (word1[i] == word2[j]) {
            res[resSize++] = i;
            j++;
        } else if (changed == 0) {
            if (j == n2 - 1 || i + 1 <= dp2[j + 1]) {
                changed = 1;
                res[resSize++] = i;
                j++;
            }
        }
    }

    free(dp2);

    if (j != n2) {
        free(res);
        *returnSize = 0;
        return NULL;
    }

    *returnSize = resSize;
    return res;
}