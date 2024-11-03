// T.C = O(mlogn + nlogn + (m*n))     S.C = O(m*n)

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        // Sort both robots and factories
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int m = robot.size();
        int n = factory.size();
        
        // dp[i][j]: minimum total distance for robots(i) using factories(j)
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        
        // Base case: if no factories are available, distance is infinite
        for(int i = 0; i < m; i++) 
        {
            dp[i][n] = LLONG_MAX;
        }
        
        // Process each factory from right to left
        for(int j = n - 1; j >= 0; j--) 
        {
            // Track distance from current factory to robots
            long long prefix = 0;
            
            // Deque to store pairs of robot index and minimum distance
            deque<pair<int, long long>> deq;
            // Initialize with base case
            deq.push_back({m, 0});
            
            // Process each robot from right to left
            for(int i = m - 1; i >= 0; i--) 
            {
                // Add distance from current robot to current factory
                prefix += abs(robot[i] - factory[j][0]);
                
                // Remove entries that exceed factory limits
                while(!deq.empty() && deq.front().first > i + factory[j][1]) 
                {
                    deq.pop_front();
                }
                
                // Maintaining monotonic property of the deque
                while(!deq.empty() && deq.back().second >= dp[i][j + 1] - prefix) 
                {
                    deq.pop_back();
                }
                
                // Adding current state to the deque
                deq.push_back({i, dp[i][j + 1] - prefix});
                
                // Calculate minimum distance for current state
                dp[i][j] = deq.front().second + prefix;
            }
        }
        
        // Return minimum total distance starting from first robot and first factory
        return dp[0][0];
    }
};