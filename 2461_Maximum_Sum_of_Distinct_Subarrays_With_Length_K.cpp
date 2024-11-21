// T.C = O(n)   S.C = O(n)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // to store window elements
        unordered_set<int> freq;

        long long result = 0;
        long long windowSum = 0;

        int i = 0;
        int j = 0;

        while(j < n)
        {
            while(freq.count(nums[j]))
            {
                // shrinking the window if current element already in set
                windowSum -= nums[i];
                // remove it from the set
                freq.erase(nums[i]);
                i++;
            }

            windowSum += nums[j];
            freq.insert(nums[j]);

            // window size equals k
            if(j-i+1 == k)
            {
                result = max(result, windowSum);

                // again shrink window
                windowSum -= nums[i];
                freq.erase(nums[i]);
                i++;
            }
            // expand
            j++;
        }

        return result;
    }
};