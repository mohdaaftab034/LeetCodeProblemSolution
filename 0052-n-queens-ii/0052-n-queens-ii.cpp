class Solution {
public:
    bool isSafe(vector<vector<bool> >& board,int row, int col, int n)
    {
        //horizontal checking
        for(int j=0; j<n; j++)
        {
            if(board[row][j]==true){
                return false;
            }
        }
        //vertical checking
        for(int i=0; i<n; i++)
        {
            if(board[i][col]==true){
                return false;
            }
        }

        //left diognal checking
        for(int i=row,j=col; j>=0 && i>=0; i--, j--)
        {
            if(board[i][j]==true){
                return false;
            }
        }
        //right diognal checking
        for(int i=row,j=col; i>=0 && j<n; i--,j++)
        {
            if(board[i][j]==true)
            {
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<vector<bool>>& board, int &ans, int n, int row)
    {
        if(row>=n){
            ans++;
            return;
        }
        for(int j=0; j<n; j++)
        {
            if(isSafe(board,row, j, n))
            {
                board[row][j] = true;
                nQueens(board,ans,n,row+1);
                board[row][j] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<bool> > board(n, vector<bool>(n,false));
        int ans = 0;
        nQueens(board, ans, n, 0);

        return ans;
    }
};