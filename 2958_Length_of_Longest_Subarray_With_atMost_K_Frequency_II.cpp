class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // poitners for window
        int l = 0;
        int r = 0;

        // store integers and their frequency
        unordered_map<int, int> unmap;

        // maximum good subarray
        int maxSubLen = 0;

        // count of integers causing a bad subarray
        int culprit = 0;

        while(r < n)
        {
            unmap[nums[r]]++;

            // if frequency goes beyond k
            if(unmap[nums[r]] == k+1)
            {
                // culprit found
                culprit++;  
            }

            if(culprit > 0)
            {
                // reduce frequency of left window element
                unmap[nums[l]]--;
                // if it works then reduce culprit count
                if(unmap[nums[l]] == k)
                {
                    culprit--;
                }
                // shrink window
                l++;
            }
        
            if(culprit == 0)
            {
                maxSubLen = max(maxSubLen, r-l+1);
            }
            r++;
        }
        return maxSubLen;
    }
};