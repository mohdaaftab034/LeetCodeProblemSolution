// LeetCode Link - "https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description"



class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        

        vector<string> result;

        string prev = ""; // Previous ko store karne ke liye

        for (string & word : words) {

            string sortedWord = word;

            sort(sortedWord.begin(), sortedWord.end());

            if(sortedWord != prev) {
                result.push_back(word);
                prev = sortedWord;
            }
        }

        return result;
    }
};
