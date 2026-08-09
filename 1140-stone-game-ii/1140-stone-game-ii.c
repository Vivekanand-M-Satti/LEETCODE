int stoneGameII(int* piles, int pilesSize) {
    int n = pilesSize;

    int** dp = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(n + 1, sizeof(int));
    }

    int* suffixSum = (int*)calloc(n, sizeof(int));

    suffixSum[n - 1] = piles[n - 1];

    for (int x = n - 2; x >= 0; x--) {
        suffixSum[x] = suffixSum[x + 1] + piles[x];
    }

    for (int x = n - 1; x >= 0; x--) {
        for (int y = 1; y <= n; y++) {
            if (x + 2 * y >= n) {
                dp[x][y] = suffixSum[x];
            } else {
                for (int j = 1; j <= 2 * y; j++) {
                    int nextM = y > j ? y : j;
                    int value =
                        suffixSum[x] - dp[x + j][nextM];

                    if (value > dp[x][y]) {
                        dp[x][y] = value;
                    }
                }
            }
        }
    }

    int result = dp[0][1];

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }

    free(dp);
    free(suffixSum);

    return result;
}