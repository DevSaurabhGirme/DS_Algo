// T.C = O(m*n)     T.C = O(m*n)

class Solution {
public:
    // vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void regionCount(vector<vector<int>>& new_grid, int i, int j)
    {
        if(i < 0 || i>= new_grid.size() || j < 0 || j >= new_grid[0].size() || new_grid[i][j] == 1)
        {
            return;
        }

        // marking as visited
        new_grid[i][j] = 1;

        // DFS calls
        regionCount(new_grid, i+1, j);
        regionCount(new_grid, i-1, j);
        regionCount(new_grid, i, j+1);
        regionCount(new_grid, i, j-1);

        /*
            for(auto& dir : directions) 
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                regionCount(matrix, new_i, new_j);
            }
        */
    
    }

    int regionsBySlashes(vector<string>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;

        // new matrix with (rows*3) number of rows and each row as a vector<int> with (cols*3) columns
        vector<vector<int>> new_grid(rows*3, vector<int>(cols*3));

        // populating the new_grid
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '/')
                {
                    new_grid[i*3][(j*3)+2] = 1;
                    new_grid[(i*3)+1][(j*3)+1] = 1;
                    new_grid[(i*3)+2][j*3] = 1;
                } 
                else if(grid[i][j] == '\\') 
                {
                    new_grid[i*3][j*3] = 1;
                    new_grid[(i*3)+1][(j*3)+1] = 1;
                    new_grid[(i*3)+2][(j*3)+2] = 1;
                }
            }
        }

        for(int i = 0; i < new_grid.size(); i++)
        {
            for(int j = 0; j < new_grid[0].size(); j++)
            {
                if(new_grid[i][j] == 0)
                {
                    regionCount(new_grid, i , j);
                    regions++;
                }
            } 
        }
        return regions;
    }
};