// T.C = O(n)   S.C = O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n = nums.size();

        unordered_map<int, int> unmap;

        for(int i = 0; i < n; i++)
        {
            unmap[nums[i]]++;
        }

        for(auto &it : unmap)
        {
            if(it . second > 1)
            {
                return true;
            }
        }
        return false;
    }
};