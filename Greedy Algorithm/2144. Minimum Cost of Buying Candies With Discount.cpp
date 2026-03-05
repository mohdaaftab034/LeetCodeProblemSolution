// LeetCode Link - https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/


// ----------------Solution-------------------
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        
        int total = 0;
        
        for(int i = 0; i < cost.size(); i++) {
            if((i + 1) % 3 != 0) {
                total += cost[i];
            }
        }
        
        return total;
    }
};
