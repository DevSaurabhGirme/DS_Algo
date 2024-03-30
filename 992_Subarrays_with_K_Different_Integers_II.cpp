class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int n = nums.size();

        int l = 0;
        int r = 0;

        // index where smallest valid subarray can be expanded
        int l_last= 0;

        // count of valid subarrays
        int subArr = 0;

        unordered_map<int ,int> unmap;

        while(r < n)
        {
            unmap[nums[r]]++;

            // shrink the window if more than k different integers are found
            while(unmap.size() > k)
            {
                unmap[nums[l]]--;

                if(unmap[nums[l]] == 0)
                {
                    unmap.erase(nums[l]);
                }
                l++;
                // assign current l for finding new smallest window
                l_last = l;
            }

            // finding smallest valid subarray by shrinking the window
            while(unmap[nums[l]] > 1)
            {
                unmap[nums[l]]--;
                l++;
            }

            if(unmap.size() == k)
            {                   // (smallest valid subArr + subarrays b/w l and l_last)
                subArr = subArr + (1 + (l - l_last));
            }

            r++;
        }
        return subArr;
    }
};