class Solution {
public:

    void DFS(vector<vector<char>>& grid, int i, int j)
    {
        // rows
        int m = grid.size();
        // columns
        int n = grid[0].size();

        // found water
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || grid[i][j] == '*')  //grid[i][j] != 1
        {
            return;
        }

        // mark as visited
        grid[i][j] = '*';

        // exploering neighbours in horizontal and vertical directions
        DFS(grid, i-1, j);
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i, j+1);
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
                    DFS(grid, i, j);
                    totalIslands++;
                }
            }
        }
        return totalIslands;
    }
};