// TLE

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int minLen = INT_MAX;

        // Iterate for all possible subarrays
        for(int i = 0; i < n; i++) 
        {
            // subarray sum
            int sum = 0;
            
            for (int j = i; j < n; j++) 
            {
                // calculating subarray sum
                sum = sum + nums[j];
                
                if(sum >= k) 
                {
                    // Update minimum length
                    minLen = min(minLen, j - i + 1);
                    
                    // No need to check further for this subarray
                    break; 
                }
            }
        }

        if(minLen == INT_MAX)
        {
            return -1;
        }

        return minLen;
    }
};