class Solution {
public:

    vector<vector<int>> farm;

    vector<vector<int>> directions{{0,1}, {0,-1},{1,0}, {-1,0}};

    void DFS(vector<vector<int>>& land,int i, int j, int& r2, int& c2)
    {
        // rows
        int m = land.size();
        // columns
        int n = land[0].size();
        land[i][j] = 0;

        r2 = max(r2, i);
        c2 = max(c2, j);

        for(auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_< n && land[i_][j_] == 1)
            {
                DFS(land, i_, j_, r2, c2);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        // rows
        int m = land.size();
        // columns
        int n = land[0].size();    

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(land[i][j] == 1)
                {
                    int r2 = -1;
                    int c2 = -1;
                
                    DFS(land, i, j, r2, c2);
                    farm.push_back({i,j,r2,c2});
                }
            }
        }
        return farm;

    }
};