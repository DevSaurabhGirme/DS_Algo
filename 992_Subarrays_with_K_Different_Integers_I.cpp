class Solution {
public:
  
    int slidingWindow(vector<int>& nums, int k)
    {
        unordered_map<int, int> unmap;

        int n = nums.size();

        // pointers as window
        int l = 0;
        int r = 0;

        // count of subarrays
        int subArr = 0;

        while(r < n)
        {
            unmap[nums[r]]++;

            // while map's size is more than different integers
            while(unmap.size() > k)
            {
                // shrink the window
                unmap[nums[l]]--;

                if(unmap[nums[l]] == 0)
                {
                    unmap.erase(nums[l]);
                }
                l++;
            }
            // count of subarrays ending with r 
            subArr = subArr + (r-l+1);
        }
        return subArr;
    }
  
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);    
    }
};