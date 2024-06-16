// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        int i = 0;
        int patchCnt = 0;
        // maximum sum we can reach using given nums array for [1,n]
        long int maxReach = 0;    
    
        while(maxReach < n)
        {
            // already getting all numbers in range [1, maxReach],(nums[i] inclusive)
            // hence already include nums[i] array without any patch required
            if(i < nums.size() && maxReach+1 >= nums[i])
            {
                maxReach = maxReach + nums[i];
                i++;
            }
            // patch required
            else
            {
                maxReach = maxReach + (maxReach+1);
                patchCnt++;
            }
        }

        return patchCnt;
    }
};