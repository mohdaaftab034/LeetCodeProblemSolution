class Solution {
private:
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            // A self-dividing number cannot contain zero, 
            // and must be divisible by each of its digits.
            if (digit == 0 || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; ++i) {
            if (isSelfDividing(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};