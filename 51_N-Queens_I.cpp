class Solution{
public :
    bool isValid(vector<string> &board, int row, int col, int n)
    {
        // checking upwards
        for(int i = row-1; i >= 0; i--)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }

        // checking left diagonally
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--,j--)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }

        // checking right diagonally
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--,j++)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void backTrack(vector<string> &board, int row, vector<vector<string>>& result, int n)
    {
        if(row >= n)
        {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(isValid(board, row, col, n))
            {
                // place the queen and explore
                board[row][col] = 'Q';

                backTrack(board, row+1, result, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        // to store final solutions
        vector<vector<string>> result;

        vector<string> board(n, string(n, '.'));

        // above created vector and row
        backTrack(board, 0, result, n);

        return result;
    }
};