
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        unordered_map<int, int> mp;

        // Count frequency of each card
        for (int num : deck) {
            mp[num]++;
        }

        int gcdVal = 0;

        // Find GCD of all frequencies
        for (auto it : mp) {
            gcdVal = gcd(gcdVal, it.second);
        }

        return gcdVal >= 2;
    }
};
