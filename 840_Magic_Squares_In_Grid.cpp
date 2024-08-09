class Solution {
public:
    bool isMagicGrid(vector<vector<int>> grid, int i, int j)
    {
        // to store numbers in square grid are distinct or not
        vector<bool> isDistinct(9, false);

        for(int r = i; r < i+3; r++)
        {
            for(int c = j; c < j+3; c++)
            {
                // check whether number is within the range 1 - 9
                int num = grid[r][c];
                if(num < 1 || num > 9)
                {
                    return false;
                }

                // duplicate found
                if(isDistinct[num-1] == true)
                {
                    return false;
                }
                // mark as seen
                isDistinct[num-1] = true;
            }
        }

        // calculating sum of all rows, columns, diagonals
        int row1Sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int row2Sum = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int row3Sum = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

        int col1Sum = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int col2Sum = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int col3Sum = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

        int diag1Sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int diag2Sum = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
    
        // if sum of all above rows, columns, diagonals are dame only then return true
        if(row1Sum == row2Sum && row2Sum == row3Sum && row3Sum == col1Sum && col1Sum == col2Sum && col2Sum == diag1Sum && diag1Sum == diag2Sum)
        {
            return true;
        }

        return false;

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        // rows
        int m = grid.size();
        // columns
        int n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m-2; i++)
        {
            for(int j = 0; j < n-2; j++)
            {
                if(isMagicGrid(grid, i, j) == true)
                {
                    count++;
                }
            }
        }
        return count;
    }
};