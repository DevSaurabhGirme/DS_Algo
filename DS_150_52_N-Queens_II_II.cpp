// T.C = O(n!)  S.C = O(n)
// we are saving the O(n) time required in isValid function from previous approach

class Solution{
public :
    void backTrack(vector<string> &board, int row, int& count, unordered_set<int>& cols, unordered_set<int>& diag, unordered_set<int>& antiDiag, int n)
    {
        if(row >= n)
        {
            count++;
            return;
        }

        for(int col = 0; col < n; col++)
        {
            int diagVal = row + col;
            int antiDiagVal = row - col;

            if(cols.find(col) != cols.end() || diag.find(diagVal) != diag.end() || antiDiag.find(antiDiagVal) != antiDiag.end())
            {
                continue;
            }

            // only when [row][col] = 'Q'
            cols.insert(col);
            diag.insert(diagVal);
            antiDiag.insert(antiDiagVal);
            board[row][col] = 'Q';

            backTrack(board, row+1, count, cols, diag, antiDiag, n);

            cols.erase(col);
            diag.erase(diagVal);
            antiDiag.erase(antiDiagVal);
        
            board[row][col] = '.';
        
        }
    }

    int totalNQueens(int n) 
    {
        // to store final solutions
        int count;

        vector<string> board(n, string(n, '.'));

        unordered_set<int> cols;
        // upward right diagonally
        unordered_set<int> diag;
        // upward left diagonally
        unordered_set<int> antiDiag;

        // above created vector and row
        backTrack(board, 0, count, cols, diag, antiDiag, n);

        return count;
    }
};