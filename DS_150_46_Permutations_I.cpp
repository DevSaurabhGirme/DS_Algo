class Solution {
public:
    // a set to store used integers
    unordered_set<int> unset;

    void Recur(vector<int>& temp, vector<int>& nums, vector<vector<int>>& result)
    {
        int n = nums.size();

        if(temp.size() == n)
        {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(unset.find(nums[i]) == unset.end())
            {
                // unused hence add to temp
                temp.push_back(nums[i]);
                // mark as used
                unset.insert(nums[i]);

                Recur(temp,nums,result);
                
                temp.pop_back();
                // remove from the set
                unset.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;

        int n = nums.size();
        vector<int> temp;

        Recur(temp, nums, result);

        return result;    
    }
};
