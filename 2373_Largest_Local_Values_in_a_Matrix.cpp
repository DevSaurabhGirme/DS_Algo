class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        vector<vector<int>> maxLocal(n-2, vector<int>(n-2));    

        // can travel only till third to last row and column to form a 3*3 matrix 
        for(int row = 0; row < n - 2; row++)
        {
            for(int col = 0; col < n - 2; col++)
            {
                maxLocal[row][col] = findLocalMax(grid, row, col);
            }
        }
        return maxLocal;
    }

    int findLocalMax(vector<vector<int>>& grid, int row, int col)
    {
        int maxVal = 0;

        for(int i = row; i <= row + 2; i++)
        {
            for(int j = col; j <= col + 2; j++)
            {
                maxVal = max(maxVal, grid[i][j]);
            }
        }
        return maxVal;
    } 


};