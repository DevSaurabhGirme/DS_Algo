// T.C = O(m*n)     S.C = O(m*n)

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        // rows
        int m = matrix.size();
        // columns
        int n = matrix[0].size();

        unordered_map<string, int> unmap;

        int maxRows = 0;

        for(auto &row : matrix)  
        {
            string nature = "";

            int firstVal = row[0];
            for(int col = 0; col < n; col++)
            {
                nature += (row[col] == firstVal) ? "S" : "N";
            }
            // incrementing count of current nature
            unmap[nature]++;
        }

        for(auto &it : unmap)
        {
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};