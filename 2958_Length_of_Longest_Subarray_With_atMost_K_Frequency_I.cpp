class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // poitners for window
        int l, r = 0;

        // store integers and their frequency
        unordered_map<int, int> unmap;

        // maximum good subarray
        int maxSubLen = 0;

        while(r < n)
        {
            // increment frequency in the map
            unmap[nums[r]]++;

            // if frequency > k
            while(l < r && unmap[nums[r]] > k)
            {
                // decrement the frequency and shrink the window
                unmap[nums[l]]--;
                l++;
            }

            // return max betwween current and existing length
            maxSubLen = max(maxSubLen, (r-l+1));
            r++;
        }

        return maxSubLen;
    }
};