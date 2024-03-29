class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int maxNum = *max_element(begin(nums), end(nums));

        int nSize = nums.size();

        int l = 0;
        int r = 0;

        long int subCount = 0;
        int maxNumCount = 0;  

        while(r < nSize)
        {
            if(nums[r] == maxNum)
            {
                maxNumCount++;
            }

            while(maxNumCount >= k)
            {
                subCount = subCount + nSize-r;

                if(nums[l] == maxNum)
                {
                    maxNumCount--;
                }
                l++;
            }
            r++;
        }

        return subCount;
    }
};