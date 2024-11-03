// T.C = O(m*n)     S.C = O(m*n)

class Solution {
public:
    //                      row-1, row, row+1
    vector<int> directions = {-1 ,  0 ,  1};

    int Recur(int row, int col, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& memo)
    {
        if(memo[row][col] != -1)
        {
            return memo[row][col];
        }

        int move = 0;

        for(int& dir : directions)
        {
            int newR = row + dir;
            int newC = col + 1;

            if(newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] > grid[row][col])
            {   
                // +1 because we found cell value satisfying the needs
                move = max(move, 1+Recur(newR, newC, grid, m ,n, memo));
            }
        }
        return memo[row][col] = move;
    }

    int maxMoves(vector<vector<int>>& grid) 
    {
        // rows
        int m = grid.size();
        // columns
        int n = grid[0].size();

        int moves = 0;

        vector<vector<int>> memo(m, vector<int>(n, -1));

        // starting from same column but different rows
        for(int row = 0; row < m; row++)
        {
            moves = max(moves, Recur(row, 0, grid, m, n, memo));
        }

        // final count of moves
        return moves;
    }
};