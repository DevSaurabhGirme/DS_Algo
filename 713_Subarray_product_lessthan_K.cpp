class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        // as we are dealing integers b/w 1 and 1000
        // for k = 0 atleast one of elements must be 0 
        if(k <= 1)
        {
            return 0;
        }

        int count = 0;
        int product = 1;

        // window 
        int left = 0;
        int right =  0;

        int n = nums.size();

        while(right < n)
        {
            product = product * nums[right];

            while(product >= k)
            {
                // shrink the window
                product = product / nums[left];
                left++;
            }
            //               count of valid subarrays within window from i to j
            count = count + (right - left + 1);
        
            right++;
        }

    return count;
    }
};