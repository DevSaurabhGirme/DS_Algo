// TC = O(n^2)    S.C = O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        // column of 1st minimum value
        int nextMinCol1 = -1;
        // column of 2nd minimum value
        int nextMinCol2 = -1;
        
        int nextMinCol1Val = -1;
        int nextMinCol2Val = -1;
        
        for (int col = 0; col < n; col++) {

            if(nextMinCol1 == -1 || grid[n - 1][col] <= nextMinCol1Val) {
                nextMinCol2 = nextMinCol1;
                nextMinCol2Val = nextMinCol1Val;
                
                nextMinCol1 = col;
                nextMinCol1Val = grid[n-1][col];
                
            } else if(nextMinCol2 == -1 || grid[n - 1][col] <= nextMinCol2Val) {
                nextMinCol2 = col;
                nextMinCol2Val = grid[n-1][col];
            }
        }

        // finding sum from last to first cell
        for (int row = n - 2; row >= 0; row--) {
            
            // stores column number of 1st minimum for current row
            int minCol1 = -1;
            // stores column number of 2nd minimum for current row
            int minCol2 = -1;
            
            // value of 1st minimum
            int minCol1Val = -1;
            // value of 2nd minimum
            int minCol2Val = -1;

            // to store final result
            int minSum = INT_MAX;
            
            // iterate over columns
            for (int col = 0; col < n; col++) {
                
                if(col != nextMinCol1) {
                    minSum = grid[row][col] + nextMinCol1Val;
                } else {
                    minSum = grid[row][col] + nextMinCol2Val;
                }
                
                // calculating minimum for each row for surrent column
                if(minCol1 == -1 || minSum <= minCol1Val) {
                    minCol2 = minCol1;
                    minCol2Val = minCol1Val;
                    
                    minCol1 = col;
                    minCol1Val = minSum;
                } else if(minCol2 == -1 || minSum <= minCol2Val) {
                    minCol2 = col;
                    minCol2Val = minSum;
                }

                // sum for each cell
                grid[row][col] += minSum;
            }
                            
            nextMinCol1 = minCol1;
            nextMinCol1Val = minCol1Val;
            
            nextMinCol2 = minCol2;
            nextMinCol2Val = minCol2Val;
                
        }

        // Return the minimum from the first row
        return nextMinCol1Val;
    }
};