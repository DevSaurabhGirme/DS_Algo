// T.C = O(m*n) S.c = O(m*n)

class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j)
    {   
        int m = grid2.size();
        int n = grid2[0].size();

        bool result = true;

        queue<pair<int, int>> que;
        que.push({i, j});
        // marking as visited
        grid2[i][j] = -1;

        while(!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1)
            {
                result = false;
            }

            for(vector<int>& dir : directions)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid2[x_][y_] == 1)
                {
                    // ma=rking as visited
                    grid2[x_][y_] = -1;
                    que.push({x_, y_});
                }
            }
        }

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int subCount = 0;
        // rows
        int m = grid2.size();    
        // columns
        int n = grid2[0].size();
    
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid2[i][j] == 1 && isSubIsland(grid1, grid2, i, j))
                {
                    // island found
                    subCount++;
                }
            }
        }

        return subCount;
    }
};