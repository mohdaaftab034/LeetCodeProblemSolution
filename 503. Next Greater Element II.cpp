LeetCode Link - "https://leetcode.com/problems/next-greater-element-ii"


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        // Initialize result array with -1 (default: no greater element)
        vector<int> ans(n, -1);

        // Stack to keep indexes of elements (monotonic stack)
        stack<int> s;

        // Traverse the array twice (simulate circular array)
        for(int i = 2*n - 1; i >= 0; i--){
            // While stack is not empty and current element is >= element at stack top
            // Pop because this element cannot be the "next greater" for anyone
            while(!s.empty() && nums[s.top()] <= nums[i % n]){
                s.pop();
            }

            // If stack is not empty, top of stack is the next greater element
            if(!s.empty()){
                ans[i % n] = nums[s.top()];
            }

            // Push current index into the stack
            s.push(i % n);
        }
        return ans;
    }
};
