// T.C = O(m*n)  S.C = O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        int m = grid.size();    // row
        int n = grid[0].size(); // column  

        // MSB = 2^n-1
        // MSB = column[0]
        // 0th column score
        int score = pow(2, n-1) * m;      // pow(2, n-j-1) here j = 0

        // counting score for other columns
        for(int j = 1; j < n; ++j)
        {
            int countofOnes = 0;

            for(int i = 0; i < m; ++i)
            {
                // if current column bit value matches MSB's value
                if(grid[i][j] == grid[i][0])
                {
                    countofOnes++;
                }
            }

            int countofZeros = m - countofOnes;

            // as we want majority of bits to be ones to determine maximum score
            // we take max beacuse if zeroes are more they will be flippedto one
            // and if ones are more they will remain as it is
            int ones = max(countofZeros, countofOnes);

            //              (number of 1's * (decimal value of that column))
            score = score + (ones * (pow(2, n-j-1)));
        }

        return score;
    }
};