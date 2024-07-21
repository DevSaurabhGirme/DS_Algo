// T.C = O(m*n)     S.C = O(1)

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        // row
        int m = matrix.size();
        // column
        int n = matrix[0].size();    
    
        vector<int> rowMin(m);
        vector<int> colMax(n);

        int r_minMax = INT_MIN;
        for(int r = 0; r < m; r++)
        {
            int r_min = INT_MAX;
            for(int c = 0; c < n; c++)
            {
                r_min = min(r_min, matrix[r][c]);
            }

            r_minMax = max(r_minMax, r_min);
        }
    
        int c_maxMin = INT_MAX;
        for(int c = 0; c < n; c++)
        {
            int c_max = INT_MIN;
            for(int r = 0; r < m; r++)
            {
                c_max = max(c_max, matrix[r][c]);
            }

            c_maxMin = min(c_maxMin, c_max);
        }

        if(r_minMax == c_maxMin)
        {
            return {r_minMax};
        }

        return {};
    
    }
}