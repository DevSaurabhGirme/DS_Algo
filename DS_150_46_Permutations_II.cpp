// T.C = O(n*n!)    S.C = O(n*n!)

class Solution {
public:
    void Permutate(int Idx, vector<int>& nums, vector<vector<int>>& result)
    {
        int n = nums.size();

        // base case, reached at end of array
        if(Idx == n)
        {
            result.push_back(nums);
            return;
        }

        for(int i = Idx; i < n; i++)
        {
            // try all possible sets of choices
            swap(nums[i], nums[Idx]);

            Permutate(Idx+1, nums, result);

            // revert back for further computing
            swap(nums[i], nums[Idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;

        int n = nums.size();

        Permutate(0, nums, result);

        return result;
    }
};