// T.C = O((n*n)*n) = O(n^3)   S.C = O(n^2)

class Solution {
public:
    int table[201][201];

    int RecurMemo(int row, int curr_Col, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int minValue = INT_MAX;

        if(table[row][curr_Col] != -1)
        {
            return table[row][curr_Col];
        }

        // reached the last row
        if(row == n-1)
        {
            return grid[row][curr_Col];
        }

        for(int nextCol = 0; nextCol < n; nextCol++)
        {
            if(nextCol != curr_Col)
            {
                // minimum answer from all next possible Columns
                minValue = min(minValue, RecurMemo(row+1, nextCol, grid));
            }
        }
        return table[row][curr_Col] = grid[row][curr_Col]+ minValue;
    }


    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        memset(table, -1, sizeof(table));

        int minSum = INT_MAX;

        for(int curr_Col = 0; curr_Col < n; curr_Col++)
        {
            minSum = min(minSum, RecurMemo(0, curr_Col, grid));
        }

        return minSum;
    }
};