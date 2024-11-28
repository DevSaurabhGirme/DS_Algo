// T.C = o(guards.size()*(m+n))     SC = O(m+n)

class Solution {
public:
    void markGuarded(int row, int col, vector<vector<int>>& grid)
    {
        // upward direction
        for(int i = row-1; i >= 0; i--)
        {
            if(grid[i][col] == 2 || grid[i][col] == 3)
            {
                break;
            }
            // marking as guarded
            grid[i][col] = 1;
        }

        // downward direction
        for(int i = row+1; i < grid.size(); i++)
        {
            if(grid[i][col] == 2 || grid[i][col] == 3)
            {
                break;
            }
            // marking as guarded
            grid[i][col] = 1;
        }

        // left direction
        for(int j = col-1; j >= 0; j--)
        {
            if(grid[row][j] == 2 || grid[row][j] == 3)
            {
                break;
            }
            // marking as guarded
            grid[row][j] = 1;
        }
    
        // right direction
        for(int j = col+1; j < grid[0].size(); j++)
        {
            if(grid[row][j] == 2 || grid[row][j] == 3)
            {
                break;
            }
            // marking as guarded
            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>> grid(m, vector<int>(n,0));     

        // marking guards' positions
        for(vector<int>&guard : guards)
        {
            int i = guard[0];
            int j = guard[1];

            grid[i][j] = 2;
        }

        // marking walls positions
        for(vector<int>&wall : walls)
        {
            int i = wall[0];
            int j = wall[1];

            grid[i][j] = 3;
        }

        for(vector<int>&guard : guards)
        {
            int i = guard[0];
            int j = guard[1];

            // marking the reach of each guard
            markGuarded(i, j, grid);
        }

        int unguarded = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    unguarded++;
                }
            }
        }

        return unguarded;

    }
};