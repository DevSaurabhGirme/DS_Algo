// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(begin(nums), end(nums));

        int result = -1;

        int i = 0;
        int j = nums.size()-1;

        while(i < j)
        {
            if(-nums[i] == nums[j])
            {
                return nums[j];
            }

            if(-nums[i] < nums[j])
            {
                j--;        
            }
            else
            {
                i++;
            }
        }
        return result;
    }
};