// S.C = O(1)   T.C = O(n)

class Solution {
public:
    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j)
    {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid2[0].size())
        {
            return true;
        }

        if(grid2[i][j] != 1)
            return true;

        // marking as visited
        grid2[i][j] = -1;

        // grid1's cell must match grid2's cell
        bool result = (grid1[i][j] == 1);

        // DFS

        // up
        result = result & isSubIsland(grid1, grid2, i-1, j);
        // down
        result = result & isSubIsland(grid1, grid2, i+1, j);
        // right
        result = result & isSubIsland(grid1, grid2, i, j+1);
        // left
        result = result & isSubIsland(grid1, grid2, i, j-1);

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