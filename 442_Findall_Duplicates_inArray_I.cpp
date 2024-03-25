// worked using extra space and time as it is a map approach

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        unordered_map<int, int> unmap;

        int n = nums.size();
        int iCnt = 0;
        // result vector containg duplicate integers
        vector<int> Arr;

        for(int i = 0; i < n; i++)
        {
            // integer found in map
            if(unmap.find(nums[i]) != unmap.end())
            {
                unmap[nums[i]]++;                    
            }
            else
            {   // didn't found hence add it
                unmap[nums[i]] = iCnt+1;
            }
        }

        // iterate through map
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