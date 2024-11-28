// T.C = O(m^2 * n)     S.C = O(n)

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        // rows
        int m = matrix.size();
        // columns
        int n = matrix[0].size();

        int maxRows = 0;

        for(auto &currRow : matrix)  
        {
            // to store inverted of currRow
            vector<int> invRow(n);

            for(int col = 0; col < n; col++)
            {
                invRow[col] = currRow[col] == 0 ? 1 : 0;
            }

            int cnt = 0;
            for(auto &row : matrix)
            {
                if(row == currRow || row == invRow)
                {
                    cnt++;
                }
            }

            maxRows = max(maxRows, cnt);
        }

        return maxRows;
    }
};