class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int num = 0;
        int idx = 0;

        vector<int> result;

        for(int i = 0; i < n; i++)
        {
            num = abs(nums[i]);
            idx = num - 1;

            if(nums[idx] < 0)
            {
                result.push_back(num);
            }
            else
            {
                //nums[idx] = -nums[idx];
                nums[idx] = -1 * nums[idx;]
            }
        }
        return result;
    }
};