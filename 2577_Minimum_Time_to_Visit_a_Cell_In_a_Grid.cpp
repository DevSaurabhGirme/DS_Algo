//T.C : O(m*n log(m*n))     S.C : O(m*n)

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    #define P pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        // cannot reach the end
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        // marking cells as visited
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // result 2D vector array
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        // to store time and coordinates
        priority_queue<P, vector<P>, greater<P>> min_heap;
        
        min_heap.push({grid[0][0], {0, 0}}); // Start at top-left corner
        result[0][0] = 0;
        
        while(!min_heap.empty()) 
        {
            // get the current time, row, and column
            int time = min_heap.top().first;
            int row  = min_heap.top().second.first;
            int col  = min_heap.top().second.second;
            
            min_heap.pop();
            
            // Reached destination
            if(row == m - 1 && col == n - 1)
                return result[m-1][n-1];
            
            // mark the current cell as visited
            if(visited[row][col]) 
                continue;
            
            visited[row][col] = true;
            
            // Explore the neighboring cells
            for(auto dir: directions) 
            {
                int r = row + dir[0];
                int c = col + dir[1];

                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                if(grid[r][c] <= time+1) 
                {
                    min_heap.push({time+1, {r, c}});
                    result[r][c] = time+1;
                }
                else if((grid[r][c] - time) % 2 == 0) 
                {
                    min_heap.push({grid[r][c]+1, {r, c}});
                    result[r][c] = grid[r][c]+1;
                }
                else
                {
                    min_heap.push({grid[r][c], {r, c}});
                    result[r][c] = grid[r][c];
                }
            }
        }
        return -1;
    }
};