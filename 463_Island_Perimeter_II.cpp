// T.C = O(m*n) S.C = O(n)

class Solution {
public:
    int m = 0;
    int n = 0;

    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    int BFS(vector<vector<int>>& grid, int i, int j)
    {
        int peri = 0;

        queue<pair<int, int>> que;
        que.push({i, j});

        // mark as visited
        grid[i][j] = -1;

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

                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0)
                {
                    peri++;
                }
                else if(grid[i_][j_] == -1)
                {
                    continue;
                }
                else
                {
                    que.push({i_,j_});
                    grid[i_][j_] = -1;
                }
            }


        }
        return peri;

    }

    int islandPerimeter(vector<vector<int>>& grid) 
    {
        // rows
        m = grid.size();
        // columns
        n = grid[0].size();

        int perimeter = 0;

        // traversing grid in search of island cells
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // island cell found
                if(grid[i][j] == 1)
                {
                    perimeter = BFS(grid, i, j);
                    return perimeter;
                }
            }
        }
        return -1;

    }
};