// Using numbers as index

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

            // if integer on idx is already -ve then the integer leading us to it has been encountered twice
            if(nums[idx] < 0)
            {
                // hence append it to the result array
                result.push_back(num);
            }
            else
            {
                // if not then negate it
                //nums[idx] = -nums[idx];
                nums[idx] = -1 * nums[idx];
            }
        }
        // return array of duplicate integers
        return result;
    }
};