class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int nSize = nums.size();

        // find maximum of nums
        int maxNum = nums[0];
        for (int j = 1; j < nSize; j++) 
        {
            if (nums[j] > maxNum) 
            {
                maxNum = nums[j];
            }
        }

        // count of valid subarrays
        long int subCount = 0;  

        // to store index of maxNum
        vector<int> maxIndices;

        for(int i = 0; i < nSize; i++)
        {
            if(nums[i] == maxNum)
            {
                maxIndices.push_back(i);
            }

            int IndSize = maxIndices.size();

            if(IndSize >= k)
            {
                // last index of maxNum where max count of maxNum >= k
                int last_i = maxIndices[IndSize-k];
            
                subCount = subCount + (last_i + 1);
            }
        }
        return subCount;
    }
};