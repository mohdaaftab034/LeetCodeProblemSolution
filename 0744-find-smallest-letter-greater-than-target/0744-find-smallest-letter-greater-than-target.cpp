class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        
        // If target is greater than or equal to all elements, wrap around to the first element
        if (it == letters.end()) {
            return letters[0];
        }
        
        return *it;
    }
};