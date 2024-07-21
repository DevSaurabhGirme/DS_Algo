// T.C = O(m*n)     S.C = O(m+n)

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

        for(int r = 0; r < m; r++)
        {
            int min_el = INT_MAX;
            for(int c = 0; c < n; c++)
            {
                min_el = min(min_el, matrix[r][c]);
            }
            rowMin[r] = min_el;
        }
    
        for(int c = 0; c < n; c++)
        {
            int max_el = INT_MIN;
            for(int r = 0; r < m; r++)
            {
                max_el = max(max_el, matrix[r][c]);
            }
            colMax[c] = max_el;
        }

        vector<int> result;

        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col])
                {
                    result.push_back(matrix[row][col]);
                }
            }
        }

        return result;
    }
};