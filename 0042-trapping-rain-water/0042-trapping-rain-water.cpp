
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        if (n < 3) return 0;

        vector<int> left_max_height(n);
        vector<int> right_max_height(n);

        int left_max = 0;
        int right_max = 0;

        // Left maximum
        for (int i = 0; i < n; i++) {

            left_max = max(left_max, height[i]);

            left_max_height[i] = left_max;
        }

        // Right maximum
        for (int i = n - 1; i >= 0; i--) {

            right_max = max(right_max, height[i]);

            right_max_height[i] = right_max;
        }

        // Calculate trapped water
        int total_water = 0;

        for (int i = 0; i < n; i++) {

            int min_height = min(left_max_height[i], right_max_height[i]);

            total_water += min_height - height[i];
        }

        return total_water;
    }
};
