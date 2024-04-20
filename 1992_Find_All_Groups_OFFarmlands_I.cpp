class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        // rows
        int m = land.size();
        // columns
        int n = land[0].size();    

        vector<vector<int>> farm;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(land[i][j] == 0)
                {
                    continue;
                }

                // iterate for current row i to find right-most column onto the farmland only
                int c2 = j;
                while(c2 < n && land[i][c2] == 1)
                {
                    c2++;
                }

                // iterate for current column j to find bottom-most row onto the farmland only
                int r2 = i;
                while(r2 < m && land[r2][j] == 1)
                {
                    r2++;
                }

                // determine bottom-rightmost coordinates for current 
                // i and j being the top-leftmost co-ordinates
                if(c2 != 0)
                {
                    c2 = c2 - 1;
                }
                if(r2 != 0)
                {
                    r2 = r2 - 1;
                }

                // above are the co-ordinates for farmland rectangle
                farm.push_back({i,j,r2,c2});

                // mark the rectangle for above farmland as visited to avoid future consideration
                for(int row = i; row <= r2; row++)
                {
                    for(int col = j; col <= c2; col++)
                    {
                        land[row][col] = 0;
                    }
                }

            }
        }
        return farm;

    }
};