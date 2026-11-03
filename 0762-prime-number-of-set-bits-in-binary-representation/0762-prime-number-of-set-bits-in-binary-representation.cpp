class Solution {
private:
    bool isPrime(int n) {
        // Since the number of set bits for a 32-bit integer is at most 32, 
        // the possible prime set counts are: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
        return (n == 2 || n == 3 || n == 5 || n == 7 || 
                n == 11 || n == 13 || n == 17 || n == 19 || 
                n == 23 || n == 29 || n == 31);
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            int setBits = __builtin_popcount(i);
            if (isPrime(setBits)) {
                count++;
            }
        }
        return count;
    }
};