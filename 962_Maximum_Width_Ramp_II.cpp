// T.C = o(n)     S.C = O(n)

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> maxAtRight(n);
        // filling the rightmost maximum integer
        maxAtRight[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--)
        {
            // comparing with next integer in maxAtRight and current integer in nums
            maxAtRight[i] = max(maxAtRight[i+1], nums[i]);
        }

        int l = 0, r = 0;
        int maxWidth = 0;

        while(r < n)
        {
            // checking width of ramp similar to sliding window
            while( r < n && nums[l] <= maxAtRight[r])
            {
                r++;
            }

            maxWidth = max(maxWidth, r-l-1);
            l++;

            // skipping unecessary rightmost part of ramp's width's considerations
            r = l + 1 + maxWidth;
        }

        return maxWidth;
    }
};