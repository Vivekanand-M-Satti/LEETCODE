char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int total = 0;

    for (int i = stoneValueSize - 1; i >= 0; i--) {
        total += stoneValue[i];

        int minimum = s1;

        if (s2 < minimum) {
            minimum = s2;
        }

        if (s3 < minimum) {
            minimum = s3;
        }

        int current = total - minimum;

        s3 = s2;
        s2 = s1;
        s1 = current;
    }

    int bob = total - s1;

    if (s1 > bob) {
        return "Alice";
    }

    if (s1 < bob) {
        return "Bob";
    }

    return "Tie";
}