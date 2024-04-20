// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();

        int l = 0;
        int r = 0;

        int minLen = INT_MAX;
        int sum = 0;

        while(r < n)
        {
            sum = sum + nums[r];

            // shrink the window
            while(sum >= target)
            {
                minLen = min(minLen, r-l+1);

                // reducing the value that just left the window
                sum = sum - nums[l];
                l++;
            }
            r++;
        }
        if(minLen == INT_MAX)
        {
            return 0;
        }
        return minLen;
    }
};