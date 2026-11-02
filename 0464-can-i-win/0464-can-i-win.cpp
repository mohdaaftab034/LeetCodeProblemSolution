class Solution {
public:
    int rec(int a, int b, int sum, int mask, vector<int>&dp){
        if(sum>=b){
            return 0;
        }
        if(dp[mask]!=-1) return dp[mask];

        for(int i=0;i<a;i++){
            if((1<<i)&mask) continue;
            if(!rec(a,b,sum+i+1,mask|(1<<i),dp)){
                return dp[mask]=1;
            }
        }
        return dp[mask]=0;
    }
    bool canIWin(int a, int b) {
        if(b==0) return true;
        if(a*(a+1)< 2*b){
            return false;
        }
        vector<int>dp((1<<a),-1);
        return rec(a,b,0,0,dp);
    }
};