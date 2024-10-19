// T.C = O(n * maxOR)   S.C = O(n * maxOR)

class Solution {
public:
    int subsetCount(int i, int currOR, vector<int>& nums, int maxOR, vector<vector<int>>& t)
    {   
        if(i >= nums.size())
        {
            if(currOR == maxOR)
            {
                return 1;
            }

            return 0;
        }
        if(t[i][currOR] != -1)
        {
            return t[i][currOR];
        }

        // take
        int tk = subsetCount(i+1, currOR | nums[i], nums, maxOR, t);
    
        // not take
        int ntk = subsetCount(i+1, currOR , nums, maxOR, t);
    
        return t[i][currOR] = tk + ntk;
    }

    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();

        int maxOR = 0;

        for(int &num : nums)
        {
            maxOR |= num;
        }    

        vector<vector<int>> t(n+1, vector<int>(maxOR+1, -1));

        int currOR = 0;
        return subsetCount(0, currOR, nums, maxOR, t);
    }
};