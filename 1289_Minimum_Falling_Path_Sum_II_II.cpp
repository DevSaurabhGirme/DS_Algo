// T.C = O(n^3)   S.C = O(n^2)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        // declaring the 2-D vector to hold mininmum path sum for every cell
        vector<vector<int>> table(n, vector<int>(n, INT_MAX));
        
        // filling the last row of the 2-D vector same as last row of grid
        for(int col = 0; col < n; col++)
        {
            table[n-1][col] = grid[n-1][col];
        }

        // finding sum from last to first cell
        for(int row = n-2; row >= 0; row--)
        {
            for(int col = 0; col < n; col++)
            {
                int minValue = INT_MAX;

                for(int nextCol = 0; nextCol < n; nextCol++)
                {
                    if(nextCol != col)
                    {
                        minValue = min(minValue, table[row+1][nextCol]);
                    }
                }

                // inserting minimum sum calculated for the cell
                table[row][col] = grid[row][col] + minValue;
            }
        }

        int minSum = INT_MAX;

        // finding minimum sum and returning it
        for(int col = 0; col < n; col++)
        {
            minSum = min(minSum, table[0][col]);
        }

        return minSum;
    }
};