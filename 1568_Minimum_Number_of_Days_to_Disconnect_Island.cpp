// T.C = O((m*n)^2)     S.C = O(m*n)

class Solution {
public:
    /////////////////  exploring function   ///////////////// 
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || grid[i][j] == 0)
        {
            return;
        }

        // marking as visited
        visited[i][j] = true;

        // hitting DFS
        DFS(grid, i+1, j , visited,m ,n);
        DFS(grid, i-1, j , visited,m ,n);
        DFS(grid, i, j+1 , visited,m ,n);
        DFS(grid, i, j-1 , visited,m ,n);
    }

    /////////////////   counting number of Islands   /////////////////
    int numberOfIslands(vector<vector<int>>& grid, int m, int n)
    {
        int islandCnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {
                    DFS(grid, i, j, visited,m ,n);
                    islandCnt++;
                }
            }
        }

        return islandCnt;
    }

    int minDays(vector<vector<int>>& grid) 
    {
        // rows
        int m = grid.size();
        // columns
        int n = grid[0].size();
        
        int islands = 0;

        islands = numberOfIslands(grid, m, n);
        
        if(islands == 0 || islands > 1)
        {
            return 0;
        }
        else
        {
            // check if we can disconnect the grid in one day
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        grid[i][j] = 0;

                        islands = numberOfIslands(grid, m, n);

                        // yes
                        if(islands == 0 || islands > 1)
                        {
                            return 1;
                        }
                        
                        // no
                        // make it land again and explore other cells
                        grid[i][j] = 1;
                        
                    }
                }
            }
        }
    
        return 2;    
    }
};