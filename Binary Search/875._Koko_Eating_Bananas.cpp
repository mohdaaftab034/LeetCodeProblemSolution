// LeetCode Link - "https://leetcode.com/problems/koko-eating-bananas/description"



class Solution {
public:

    bool canEatAllBananas(vector<int>& piles, int mid, int h) {

        int actualHours = 0;

        for(int & x : piles) {
            actualHours += x/mid;

            if(x % mid > 0) {
                actualHours++;
            }
        }

        return actualHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(begin(piles), end(piles)); 

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(canEatAllBananas(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
