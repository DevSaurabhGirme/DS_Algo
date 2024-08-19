// TLE

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
            vector<long int> curr(n);
            // iterating on current row
            for(int j = 0; j < n; j++)
            {
                // iterating on prev row
                for(int k = 0; k < n; k++)
                {
                    curr[j] = max(curr[j], prev[k]+points[i][j] - abs(j-k));
                }
            }

            prev = curr;
        }

        // (n-1)th row becomes prev
        return *max_element(begin(prev), end(prev));
    }
};