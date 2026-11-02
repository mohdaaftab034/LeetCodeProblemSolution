class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int count = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '-') continue;
            else if(s[i] >= 97 && s[i] <= 122){
                char ch;
                ch = s[i]-32;
                ans += ch;
                count++;
            }
            else{
                ans += s[i];
                count++;
            }
            if(count == k){
                count = 0;
                ans += '-';
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans[0] == '-') return ans.substr(1);
        return ans;
    }
};