//T.C : O(m*n log(m*n))     S.C : O(m*n)

class Solution {
public:
    #define P pair<int, pair<int, int>>
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int minimumObstacles(vector<vector<int>>& grid) 
    {   
        // rows
        int m = grid.size();

        // columns
        int n = grid[0].size();

        // result vector to store distance from (0,0) to (i,j)
        vector<vector<int>> answer(m, vector<int>(n, INT_MAX));

        answer[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> min_heap;

        // weight, {i,j}
        min_heap.push({0, {0,0}});

        while(!min_heap.empty())
        {
            auto curr = min_heap.top();
            min_heap.pop();

            int dist = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for(auto &dir : directions) 
            {
                int x = i + dir[0];
                int y = j + dir[1];

                // check for valid cell
                if(x < 0 || x >= m || y < 0 || y >= n) 
                {
                    continue;
                }

                int wt = (grid[x][y] == 1) ? 1 : 0;

                // shorter distance found
                if(dist + wt < answer[x][y]) 
                {
                    answer[x][y] = dist + wt;
                    min_heap.push({dist+wt, {x, y}});
                }
            }
        }

        // shortest distance representing minimum number of removals
        return answer[m-1][n-1];
    }
};