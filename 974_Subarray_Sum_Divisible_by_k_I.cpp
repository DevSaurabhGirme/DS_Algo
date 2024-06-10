// T.C = O(n^2) TLE

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size();

        int count = 0;

        // calculating prefix sum
        for(int i = 1; i < n; i++)
        {
            nums[i] += nums[i-1];
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];

                if(sum % k == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};