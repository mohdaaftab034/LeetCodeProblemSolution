class Solution {
public:
    int countSegments(string s) {
        // add space at end, to handle extra checks
        s = s + ' ';
        bool wordExist = false;   // check a word exist or not
        int segments = 0;
        int i=0, n = s.length();

        while(i < n){
            // if space and have word exist before
            if(s[i] == ' ' && wordExist){
                segments++;
                wordExist = false;
            }
            
            // anything expect space, to make a word
            else if(s[i] != ' '){
                wordExist = true;
            }
            i++;
        }
        return segments;
    }
};