class Solution {
private:
    bool isGood(int n) {
        bool hasChanged = false;
        while (n > 0) {
            int digit = n % 10;
            // Numbers 3, 4, and 7 are invalid when rotated
            if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            // Numbers 2, 5, 6, and 9 change to a different valid digit upon rotation
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasChanged = true;
            }
            n /= 10;
        }
        return hasChanged;
    }

public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }
};