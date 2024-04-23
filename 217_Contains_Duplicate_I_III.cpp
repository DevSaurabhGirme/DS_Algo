// T.C = O(nlogn)   S.C = O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n = nums.size();

        nums.sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};