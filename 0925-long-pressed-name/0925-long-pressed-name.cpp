
class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int i = 0;
        int j = 0;

        while (j < typed.length()) {

            // Characters must match
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            }

            // Allow repeated characters in typed
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }

            else {
                return false;
            }
        }

        return i == name.length();
    }
};
