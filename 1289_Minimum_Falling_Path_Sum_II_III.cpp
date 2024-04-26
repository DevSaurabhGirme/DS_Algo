// T.C = O(n^2)   S.C = O(n^2)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        // declaring the 2-D vector to hold mininmum path sum for every cell
        vector<vector<int>> table(n, vector<int>(n, INT_MAX));
        
        // column of 1st minimum value
        int nextMinCol1 = -1;
        // column of 2nd minimum value
        int nextMinCol2 = -1;

        // filling the last row of the 2-D vector same as last row of grid
        for(int col = 0; col < n; col++)
        {
            table[n-1][col] = grid[n-1][col];

            if(nextMinCol1 = -1 || table[n-1][col] <= table[n-1][nextMinCol1])
            {
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = col;
            }
            else if(nextMinCol2 == -1 || table[n-1][col] <= table[n-1][nextMinCol2])
            {
                nextMinCol2 = col;
            }
        }

        // finding sum from last to first cell
        for(int row = n-2; row >= 0; row--)
        {
            // stores 1st minimum for current row
            int minCol1 = -1; 
            // stores 2nd minimum for current row
            int minCol2 = -1;

            for(int col = 0; col < n; col++)
            {
                if(col != nextMinCol1)
                {
                    table[row][col] = grid[row][col] + table[row+1][nextMinCol1];
                }
                else
                {
                    table[row][col] = grid[row][col] + table[row+1][nextMinCol2];
                }

                // updating minimum column for current row
                if(minCol1 == -1 || table[row][col] <= table[row][minCol1])
                {
                    minCol2 = minCol1;
                    minCol1 = col;
                }
                else if(minCol2 == -1 || table[row][col] <= table[row][minCol2])
                {
                    minCol2 = col;
                }
            }

            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }

        return table[0][nextMinCol1];
    }
};