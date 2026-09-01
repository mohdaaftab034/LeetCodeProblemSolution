class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> t(n, false);

        // t[i] = true : means, mai i tak pahuch sakta hu
        // t[i] = false : means, nhi pahuch sakta hu
        t[0] = true;
    
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--){

                if(t[j] == true && j + nums[j] >= i) {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n-1];
    }
};