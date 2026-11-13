class Solution {
public:
    bool validTicTacToe(vector<string>& board) {

        int xCount = 0, oCount = 0;

        // Count X and O
        for (auto &row : board) {
            for (char ch : row) {
                if (ch == 'X') xCount++;
                else if (ch == 'O') oCount++;
            }
        }

        // X always plays first
        if (xCount != oCount && xCount != oCount + 1) {
            return false;
        }

        // Check winning conditions
        auto win = [&](char ch) {

            // Check rows
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == ch &&
                    board[i][1] == ch &&
                    board[i][2] == ch) {
                    return true;
                }
            }

            // Check columns
            for (int j = 0; j < 3; j++) {
                if (board[0][j] == ch &&
                    board[1][j] == ch &&
                    board[2][j] == ch) {
                    return true;
                }
            }

            // Check diagonals
            if (board[0][0] == ch &&
                board[1][1] == ch &&
                board[2][2] == ch) {
                return true;
            }

            if (board[0][2] == ch &&
                board[1][1] == ch &&
                board[2][0] == ch) {
                return true;
            }

            return false;
        };

        bool xWin = win('X');
        bool oWin = win('O');

        // Both players cannot win
        if (xWin && oWin) return false;

        // X wins only if X played last
        if (xWin && xCount != oCount + 1) {
            return false;
        }

        // O wins only if counts are equal
        if (oWin && xCount != oCount) {
            return false;
        }

        return true;
    }
};