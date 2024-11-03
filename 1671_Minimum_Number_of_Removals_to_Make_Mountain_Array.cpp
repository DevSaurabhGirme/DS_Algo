// T.C = O(n^2)     S.C = O(n)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);
    
        // LIS
        for(int i = 0; i < n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[i] > nums[j])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // LDS
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i+1; j < n; j++)
            {
                if(nums[i] > nums[j])
                {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int minRem = n;

        // considering each integer as peak
        for(int i = 0; i < n; i++)
        {
            // maintaing the subsequences for a valid mountain 
            if(LIS[i] > 1 && LDS[i] > 1)
                minRem = min(minRem, n- LIS[i] - LDS[i] + 1);
        }

        return minRem;
    }
};