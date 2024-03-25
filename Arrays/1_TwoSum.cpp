#include <unordered_map>
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // Declare an unordered map to store intergers and their corredponding index
        unordered_map<int, int> unmap;

        for(int i = 0; i < nums.size(); i++)
        {
            // Find the complemnent and check whether it is present in the unordered_map we declared
            if(mp.find(target - nums[i]) == mp.end())
            {   
                // not found in the unordered_mapas the identifier returned by the mp.find() function travesres till the end
                // and finally points beyond the last element of the container.
                // hence we add this integer and its index to the map
                mp[nums[i]] = i;
            }
            else
            {
                //found the complement therefore we return the element and it's index
                return {mp[target-nums[i]],i};
            }
        }

        // If no pair ata all is found then return {-1, -1}value
        return {-1 , -1};
    }
};
