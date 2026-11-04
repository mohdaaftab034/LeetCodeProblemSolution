class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case for overflow (INT_MIN / -1 = INT_MAX + 1, which overflows)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both to long long and take absolute values to prevent overflow during abs()
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long quotient = 0;

        // Bit manipulation for fast division (exponential subtraction)
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};