class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n = nums.size();

        // map to store the current/running sum and the coresponding index
        unordered_map<int, int> unmap;
        // initializing sum to zero and index to -1
        unmap[0] = -1;

        int Current_Sum = 0;    

        // length of maxinmum subarray
        int maxsubArr = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                Current_Sum += 1;
            }
            else if(nums[i] == 0)
            {
                Current_Sum += -1;
            }

            // if new index is found then we find maximum length of contiguous array
            if (unmap.find(Current_Sum) != unmap.end())
            {
                maxsubArr = max(maxsubArr, i - unmap[Current_Sum]);
            }
            // if not found then we update our map
            else
            {
                unmap[Current_Sum] = i;
            }
        }
        
        return maxsubArr;
    }
};