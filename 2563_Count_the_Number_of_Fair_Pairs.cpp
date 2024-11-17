// T.C = O(n * logn)

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        int n = nums.size();

        long int pairs = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-1; i++) 
        {
            // gives index of firstc element not less than (lower - nums[i])
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums); 
            
            // number of pairs having sum less than lower
            int x   = idx - 1 - i;

            // gives index of first element greater than (upper - nums[i])
            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); 

            // number of pairs having sum less than equal to upper
            int y = idx - 1 - i;

            // getting number of pairs satisfying given condition for i
            pairs += (y-x);
        }

        return pairs;
    }
};