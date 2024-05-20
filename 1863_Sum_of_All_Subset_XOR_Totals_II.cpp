//T.C = O(2^n)  S.C = O(n)

class Solution {
public:

    int findSubsets(vector<int>& nums, int i, int XOR)
    {
        // if i goes outofbound
        if(i == nums.size())
        {
            return XOR;
        }

        int include = findSubsets(nums, i+1, nums[i] ^ XOR);
        int exclude = findSubsets(nums, i+1, XOR);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) 
    {
    
        findSubsets(nums, 0, 0);

    }
};