int smallestNumber(int n, int t) {
    int candidate = n;

    while (1) {
        int product = 1;
        int num = candidate;

        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }

        if (product % t == 0) {
            return candidate;
        }

        candidate++;
    }
}