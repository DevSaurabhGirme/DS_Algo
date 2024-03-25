// using extra space unordered maps
// TC = O(n+m)

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> unmap;
        
        int len = nums.size();
        int count = 1;

        for(int i = 0; i < len; i++)
        {
            if(unmap.find(nums[i]) == unmap.end())
            {
                // not found
                unmap[nums[i]] = count;
            }
            else
            {
                // found in map hence incerement its count
                unmap[nums[i]]++;
            }
        }

        // iterate through map and look for integers whose count is greater than or 2
        for (auto it = unmap.begin(); it != unmap.end(); ++it) 
        {   
           if((it -> second) >= 2)
           {
                // returns the 1st iteger found
                // ! first here doesn't mean first element but the left column of our map which holds the integer
                return it -> first;
           }
        }
        // if found nothing
        return 0;
    }
};