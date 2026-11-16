class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            if(prefixSum[i] == k) {
                count++;
            }

            int val = prefixSum[i] - k;
            if(mp.find(val) != mp.end()) {
                count += mp[val];
            }

            if(mp.find(prefixSum[i]) == mp.end()) {
                mp[prefixSum[i]] = 0;
            }

            mp[prefixSum[i]]++;
        }
        
        return count;
    }
};