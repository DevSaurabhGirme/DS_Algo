class Solution {
public:
    // vector for directions to explore
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    void BFS(vector<vector<char>>& grid, int i, int j)
    {
        // rows
        int m = grid.size();
        // columns
        int n = grid[0].size();

        queue<pair<int, int>> que;
        que.push({i, j});

        // mark as visited
        grid[i][j] = '*';

        while(!que.empty())
        {
            // retrieving first element
            auto it = que.front();
            que.pop();

            // exploring all the directions
            for(auto &dir : directions)
            {
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];

                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != '1')
                {
                    continue;
                }
                else
                {
                    // mark visited
                    que.push({i_,j_});
                    grid[i_][j_] = '*';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        // rows
        int m = grid.size();
        // columns
        int n = grid[0].size();
    
        int totalIslands = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    BFS(grid, i, j);
                    totalIslands++;
                }
            }
        }
        return totalIslands;
    }
};