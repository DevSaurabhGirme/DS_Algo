// worked using extra space and time as it is a map approach

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        unordered_map<int, int> unmap;

        int n = nums.size();
        int iCnt = 1;
        vector<int> Arr;

        for(int i = 0; i < n; i++)
        {
            if(unmap.find(nums[i]) == unmap.end())
            {
                // not found
                unmap[nums[i]] = iCnt;
            }
            else
            {
                // found in map hence incerement its count
                unmap[nums[i]]++;
            }
        }

        for(auto i = unmap.begin(); i != unmap.end(); i++)
        {
            if((i -> second) >= 2) //(unmap[i]) >= 2
            {
                Arr.push_back(i -> first); //(unmap[i]) >= 2
            }             
        }

        return Arr;
                
    }
};