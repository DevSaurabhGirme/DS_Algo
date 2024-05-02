// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        // set to store original integer
        set<int> occured;
        int result = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            // counterpart found
            if(occured.find(-nums[i]) != occured.end())
            {
                result = max(result, abs(nums[i]));
            }
            // new entry to the set
            occured.insert(nums[i]);
        }

        return result;
    }
};