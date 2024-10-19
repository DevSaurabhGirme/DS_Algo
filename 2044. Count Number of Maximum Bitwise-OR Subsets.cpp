// T.C = O(2^n)     S.C = O(1)

class Solution {
public:
    int subsetCount(int i, int currOR, vector<int>& nums, int maxOR)
    {   
        if(i >= nums.size())
        {
            if(currOR == maxOR)
            {
                return 1;
            }

            return 0;
        }

        // take
        int tk = subsetCount(i+1, currOR | nums[i], nums, maxOR);
    
        // not take
        int ntk = subsetCount(i+1, currOR , nums, maxOR);
    
        return tk + ntk;
    }

    int countMaxOrSubsets(vector<int>& nums) 
    {
        int maxOR = 0;

        for(int &num : nums)
        {
            maxOR |= num;
        }    

        int currOR = 0;
        return subsetCount(0, currOR, nums, maxOR);
    }
};