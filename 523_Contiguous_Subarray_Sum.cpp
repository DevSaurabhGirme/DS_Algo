class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mod;
        mod[0] = -1;

        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            int modulo = sum % k;

            // remainder seen earlier
            if(mod.find(modulo) != mod.end())
            {
                if(i - mod[modulo] >= 2)
                {
                    return true;
                }
            }
            else
            {
                // new remainder
                mod[modulo] = i;
            }
        }
        return false;
    }
};