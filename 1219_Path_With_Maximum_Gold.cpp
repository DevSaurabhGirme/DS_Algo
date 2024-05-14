// T.C = m*n * 4^(grid[i][j] != 0)
// S.C = O(4^(grid[i][j] != 0))

class Solution {
public:
    vector<vector<int>> directions{{-1,0}, {1,0}, {0,1}, {0,-1}};
    
    findGoldMax(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0)
        {
            return 0;
        }

        int OrgGoldVal = grid[i][j];
        // marking as visited for current quest
        grid[i][j] = 0;
    
        // store result of search for ablove starting grid
        int GoldMax = 0;

        for(vector<int> &dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
        
            GoldMax = max(GoldMax, findGoldMax(grid, new_i, new_j));
        }


        // reset it for further iterations
        grid[i][j] = OrgGoldVal;

        return OrgGoldVal + GoldMax;

    }

    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int GoldMax = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // walk the path only if gold is present
                if(grid[i][j]!= 0)
                {
                    GoldMax = max(GoldMax, findGoldMax(grid, i, j));
                }
            }
        }

        return GoldMax;
    }
};