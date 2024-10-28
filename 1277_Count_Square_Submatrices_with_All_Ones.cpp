// S.C = O(m*n)     T.C = O(m*n)

class Solution {
public:
    int m, n;
    int Recur(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& t) 
    {    
        // out of bound
        if (i >= grid.size() || j >= grid[0].size()) 
            return 0;

        if (grid[i][j] == 0)
            return 0;

        // already calculated
        if (t[i][j] != -1)
            return t[i][j];

        // right
        int right = Recur(i, j + 1, grid, t);
        // diagonal
        int diagonal = Recur(i + 1, j + 1, grid, t);
        // bottom
        int below = Recur(i + 1, j, grid, t);

        return t[i][j] = 1 + min({right, diagonal, below});
    }

    int countSquares(vector<vector<int>>& grid) 
    {
        int sqSubs = 0;
        // row
        m = grid.size();
        // column
        n = grid[0].size();
    
        vector<vector<int>> t(m, vector<int>(n, -1));
        
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                sqSubs += Recur(i, j, grid, t);
            }
        }
        return sqSubs;
    }
};