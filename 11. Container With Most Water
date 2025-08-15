LeetCode Link - "https://leetcode.com/problems/container-with-most-water/description"


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int leftpr = 0, rightpr = n-1;
        int max_water = 0;
        while(leftpr<rightpr)
        {
            int width = rightpr-leftpr;
            int ht = min(height[leftpr],height[rightpr]);
            int area = width * ht;
            max_water = max(max_water,area);
            if(height[leftpr]<height[rightpr])
            {
                leftpr++;
            }
            else{
                rightpr--;
            }
        }
        return max_water;
    }
};
