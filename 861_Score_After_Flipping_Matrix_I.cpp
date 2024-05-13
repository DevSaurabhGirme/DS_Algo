// T.C = O(m*n)  S.C = O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        int m = grid.size();    // row
        int n = grid[0].size(); // column  

        for(int i = 0; i < m; i++)
        {
            // check if MSB of every row is 1 or not if not toggle the entire row
            if(grid[i][0] == 0)
            {
                // toggle the row
                for(int j = 0; j < n; j++)
                {
                    // 1 -> 0 ][ 0 -> 1
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for(int j = 1; j < n; j++)
        {
            int countZero = 0;

            // keep track of number of zeros in every column
            for(int i = 0; i < m; i++)
            {
                if(grid[i][j] == 0)
                {
                    countZero++;
                }
            }

            int countOne = m - countZero;
            if(countZero >= countOne)
            {
                // toggle that column
                for(int i = 0; i < m; i++)
                {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        int score = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int value = grid[i][j] * pow(2, n - j - 1);
            
                score += value;
            }
        }
        return score;

    }
};