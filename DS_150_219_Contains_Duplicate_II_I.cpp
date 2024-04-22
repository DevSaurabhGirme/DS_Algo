#include <unordered_map>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // to store number and its index
        unordered_map<int, int> unmap;

        for(int i = 0;i < n; i++)
        {
            // if integer present in map
            if(unmap.find(nums[i]) != unmap.end() && abs(mp[nums[i]] - i) <= k)
            {
                return true;
            }
            // if not add it along with its index
            unmap[nums[i]] = i;
        }

        return false;
    }
};