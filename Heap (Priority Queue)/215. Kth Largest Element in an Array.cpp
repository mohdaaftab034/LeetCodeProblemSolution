// Leetcode - https://leetcode.com/problems/kth-largest-element-in-an-array/description/?utm=codolio


// --------------------Solution - 1----------------------
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sort an element in descending order
        sort(begin(nums), end(nums), greater<int>());

        return nums[k-1];
    }
};



// -------------------------Solution - 2---------------------------
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int &num : nums) {
            pq.push(num);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};
