// T.C = O(2^n * length 0f subset)     S.C = O(2^n * length 0f subset)

class Solution {
public:

    void findSubsets(vector<int>& nums, int i, vector<int>& curr_Subset, vector<vector<int>>& subsets)
    {
        // if i goes outofbound
        if(i == nums.size())
        {
            subsets.push_back(curr_Subset);
            return;
        }

        curr_Subset.push_back(nums[i]);
        findSubsets(nums, i+1, curr_Subset, subsets);
        curr_Subset.pop_back();
        findSubsets(nums, i+1, curr_Subset, subsets);
    }

    int subsetXORSum(vector<int>& nums) 
    {
        // to hold subsets
        vector<vector<int>> subsets;    
    
        vector<int> curr_Subset;
        findSubsets(nums, 0, curr_Subset, subsets);

        int result = 0;

        for(vector<int>& subset : subsets)
        {
            int Xor = 0;
            for(int &num : subset)
            {
                Xor ^= num;
            }

            result += Xor;
        }
    
        return result;
    }
};