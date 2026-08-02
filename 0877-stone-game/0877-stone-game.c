bool stoneGame(int* piles, int pilesSize) {
    /**
    return true;
    */
    int n = pilesSize;
    int* dp = calloc(n, sizeof(int));

    for (int left = n - 1; left >= 0; left--) {
        for (int right = left; right < n; right++) {
            int turn = (left + right) % 2;

            if (left == right) {
                dp[right] = 0;
            } else {
                if (turn) {
                    int takeLeft = piles[left] + dp[right];
                    int takeRight = piles[right] + dp[right - 1];

                    dp[right] = takeLeft > takeRight
                        ? takeLeft
                        : takeRight;
                } else {
                    dp[right] = dp[right] < dp[right - 1]
                        ? dp[right]
                        : dp[right - 1];
                }
            }
        }
    }

    int total = 0;

    for (int i = 0; i < n; i++) {
        total += piles[i];
    }

    bool result = dp[n - 1] > total - dp[n - 1];

    free(dp);

    return result;
}