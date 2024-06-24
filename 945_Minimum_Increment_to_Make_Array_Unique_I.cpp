class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int moves = 0;

        for(int i = 1; i < n; i++)
        {
//            int nums[i-1] = nums[i-1];
//            int nums[i] = nums[i];

            if(nums[i-1] >= nums[i])
            {
                moves = moves+(nums[i-1] - nums[i])+1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return moves;

    }
};