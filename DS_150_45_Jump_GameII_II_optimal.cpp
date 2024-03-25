// optimum approach with no confusing cases of jump counter increment

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        int totalJumps = 1;

        // last index
        int dest = n-1;

        // represents maximum reachable index
        int maxCoverage = 0;
        
        // index where we could reach for that particular window
        int lastJumpIdx = 0;

        /*window here represents maximum integer for particular index or the window itself*/
        /*[0] [1] [2] [3] [4] [5] [6] [7]   */
        /* 2,  4,  1,  2,  3,  1,  1,  2    */
        /*|_| |_____| |_________| |______|  */
        if(n == 1)
        {
            return 0;
        }

        for(int i = 0; i < n; i++)
        {
            maxCoverage = max(maxCoverage, i + nums[i]);

            if(i != dest)
            {
                // check if we are at the destination
                if(maxCoverage >= dest)
                {
                    return totalJumps;
                }
            }

            // window is completely studied
            if(i == lastJumpIdx)
            {
                lastJumpIdx = maxCoverage;
                totalJumps++;
            }

        }
    
        return totalJumps;
    }
};