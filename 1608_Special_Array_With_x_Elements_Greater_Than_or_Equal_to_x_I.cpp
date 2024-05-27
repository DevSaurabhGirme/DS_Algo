class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int x = 0; x <= n; x++)
        {
            // returns iterator pointing to first integer >= x
            int Idx = lower_bound(begin(nums), end(nums), x) - begin(nums);

            // gives count of integers > x
            int count = n - Idx;

            if(count == x)
            {
                return x;
            }
        }
        return -1;
    }
};