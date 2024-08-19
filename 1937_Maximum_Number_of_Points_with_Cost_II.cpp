class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        // rows
        int m = points.size();    
        // columns
        int n = points[0].size();

        vector<long int> prev(n);

        int score = 0;

        // initializing 0th row
        for(int col = 0; col < n; col++)
        {
            prev[col] = points[0][col];
        }

        for(int i = 1; i < m; i++)
        {
            // to store best values on left side of current cell
            vector<long int> left(n,0);
            // to store best values on right side of current cell
            vector<long int> right(n,0);

            left[0] = prev[0];
            for(int j = 1; j < n; j++)
            {
                left[j] = max(prev[j], left[j-1]-1);
            }

            right[n-1] = prev[n-1];
            for(int j = n-2; j >= 0; j--)
            {
                right[j] = max(prev[j], right[j+1]-1);
            }

            vector<long int> curr(n);
            for(int j = 0; j < n; j++)
            {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }
            
            prev = curr;
        }

        // (n-1)th row becomes prev
        return *max_element(begin(prev), end(prev));
    }
};