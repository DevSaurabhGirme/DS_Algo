// T.C = O(m*n) S.C = O(1)

class Solution {
public:
    int m = 0;
    int n = 0;

    int DFS(vector<vector<int>>& grid, int i, int j)
    {
        int peri = 0;

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            peri++;
            return peri;
        }

        // visiting again
        if(grid[i][j] == -1)
        {
            return 0;
        }

        // mark as visited
        grid[i][j] = -1;

        // retrieving perimeter from all possible directions for current island position(cell)
        int peri1 = DFS(grid, i+1, j);
        int peri2 = DFS(grid, i-1, j);
        int peri3 = DFS(grid, i, j+1);
        int peri4 = DFS(grid, i, j-1);

        // sum it up to get final perimeter
        peri = peri1+peri2+peri3+peri4;

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
                    perimeter = DFS(grid, i, j);
                    return perimeter;
                }
            }
        }
        return -1;

    }
};