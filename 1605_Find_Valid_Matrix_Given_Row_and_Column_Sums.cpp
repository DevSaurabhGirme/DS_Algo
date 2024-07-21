// S.C = O(1)   T.C = O(m+n)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        int m = rowSum.size();
        int n = colSum.size();    
    
        vector<vector<int>> valid(m, vector<int>(n, 0));

        int i = 0; // row
        int j = 0; // column

        while(i < m && j < n)
        {
            valid[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= valid[i][j];
            colSum[j] -= valid[i][j];
        
            if(rowSum[i] == 0)
            {
                i++;
            }

            if(colSum[j] == 0)
            {
                j++;
            }
        }

        return valid;
    }
};