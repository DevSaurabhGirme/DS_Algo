class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        int n = nums.size();

        // position of minK
        int minKPos = -1;
        // position of maxK
        int maxKPos = -1;

        // position of integer such that it is <k or >k
        int culpritIdx = -1;

        // minimum of minKPos and maxKPos
        int minofmin = 0;

        int temp = 0;

        // count of valid subarrays
        long int subArr = 0;

        for(int i = 0;i < n; i++)
        {
            if(nums[i] == minK)
            {
                minKPos = i;
            }
            if(nums[i] == maxK)
            {
                maxKPos = i;
            }

            // finding culprit;s index
            if((nums[i] < minK) || (nums[i] > maxK))
            {
                culpritIdx = i;
            }
            
            minofmin = min(minKPos, maxKPos);

            temp = minofmin - culpritIdx;

            if(temp < 0)
            {
                // no valid subarrays 
                temp = 0;
            }
            else
            {
                temp = temp;
            }
            
            subArr = subArr + temp;

            //subArr += (temp <= 0) ? 0 : temp;

        }
        
        return subArr;

    }
};