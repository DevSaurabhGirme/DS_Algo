class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        unordered_map<int, int> unmap;

        int n = nums.size();
        int iCnt = 0;
        vector<int> Arr;

        for(int i = 0; i < n; i++)
        {
            if(unmap.find(nums[i]) != unmap.end())
            {
                unmap[nums[i]]++;                    
            }
            else
            {
                unmap[nums[i]] = iCnt+1;
            }
        }

        for(auto i = unmap.begin(); i != unmap.end(); i++)
        {
            if((unmap[i]) >= 2)
            {
                Arr.push_back(unmap[i]);
            }             
        }

        return Arr;
                
    }
};