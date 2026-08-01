bool predictTheWinner(int* nums, int numsSize) {
    if (numsSize <= 1) return true;

    int n = numsSize;
    int dp[n][n];

    // Base case: single element
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }

    // Fill by increasing subarray length
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            int pickLeft  = nums[i] - dp[i + 1][j];
            int pickRight = nums[j] - dp[i][j - 1];
            dp[i][j] = (pickLeft > pickRight) ? pickLeft : pickRight;
        }
    }

    return dp[0][n - 1] >= 0;
}