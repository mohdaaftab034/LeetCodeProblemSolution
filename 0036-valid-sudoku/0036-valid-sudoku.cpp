class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];
                if (val == '.') continue;

                // Create unique string identifiers for row, column, and 3x3 sub-box
                string rowKey = string(1, val) + " in row " + to_string(i);
                string colKey = string(1, val) + " in col " + to_string(j);
                string boxKey = string(1, val) + " in box " + to_string(i / 3) + "-" + to_string(j / 3);

                // If any identifier already exists, the board is invalid
                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }

                // Record the current occurrences
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }

        return true;
    }
};