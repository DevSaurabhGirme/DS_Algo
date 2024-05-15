class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,-1}, {0,1}};

    int n;

    // BFS function
    bool check(vector<vector<int>>& nearestTheifDist, int SF)
    {
        if(nearestTheifDist[0][0] < SF)
        {
            return false;
        }

        queue<pair<int, int>> que;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        que.push({0,0});
        visited[0][0] = true;

        while(!que.empty())
        {
            int curr_i = que.front().first;
            int curr_j = que.front().second;

            que.pop();

            // reaches the end of the grid
            if(curr_i == n-1 && curr_j == n-1)
            {
                return true;
            }

            // exploring neighbors
            for(vector<int>& dir : directions)
            {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];
            
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visited[new_i][new_j] != true)
                {
                    if(nearestTheifDist[new_i][new_j] < SF)
                    {
                        // skip the cell
                        continue;
                    }
                    que.push({new_i,new_j});
                    visited[new_i][new_j] = true;
                }

            }
        }
        return false;

    }

    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        n = grid.size();

        if(grid[0][0] == 1)
        {
            return 0;
        }

        // S-1 Calcualte distance of nearest theif from each cell by asking theif cells to call BFS simultaneously
        // Multi-source BFS

        vector<vector<int>> nearestTheifDist(n, vector<int>(n,-1));
        
        // queue for theif cells
        queue<pair<int, int>> que;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // push all the cells of theives
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // thief cell
                if(grid[i][j] == 1)
                {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;

        while(!que.empty())
        {
            // number of nodes in a single level
            int size = que.size();

            // process these nodes in a particular level simultaneously
            while(size--)
            {
                int curr_i = que.front().first;
                int curr_j = que.front().second;
            
                que.pop();

                // insert distance of nearest thief to current cell as the level they are currently in
                // since these are the theives themselves the level is 0 hence the distance is also 0
                nearestTheifDist[curr_i][curr_j] = level; 
            
                // applying BFS on neighbours of level one cells
                for(vector<int>& dir : directions) 
                {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    // check if the cell is valid and not visited yet
                    if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j])
                    {
                        continue;
                    }

                    que.push({new_i,new_j});

                    // mark this cell as visited
                    visited[new_i][new_j] = true;
                }
            }
            level++;
        }

        // S-2 apply Binary Search

        int l = 0;
        int r = 400;

        int max_SF = 0;

        while (l <= r)
        {
            int mid_SF = l + (r-l)/2;

            // check if we find a path with SF >= mid_SF
            if(check(nearestTheifDist, mid_SF))
            {
                // if yes then check for higher SF
                max_SF = mid_SF;
                l = mid_SF + 1;
            }
            else
            {
                // if no then check for lower SF
                r = mid_SF - 1;
            }
        
        }   

       return max_SF; 

    }
};