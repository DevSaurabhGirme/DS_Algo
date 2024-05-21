class Solution {
public:
    // holding final subset result
    vector<vector<int>> result;

    void Recur(int idx, vector<int>& nums, vector<int>& temp)
    {
        if(idx >= nums.size())
        {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        Recur(idx + 1, nums, temp);  // option 1: Take it

        temp.pop_back();            // option 2 : Don't take it
        Recur(idx + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        // for holding subset
        vector<int> temp;   
    
        Recur(0, nums, temp);

        return result;
    }
};