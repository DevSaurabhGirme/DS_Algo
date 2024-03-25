class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        unordered_map<int, int> unmap;

        // we consider the posibility that the subarray may start with 0
        unmap[0] = 1;

        int Sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            // calculate cumulative sum
            Sum = Sum + nums[i];

            // it indicates that there exists at least one subarray whose sum is equal to goal up to the current position in the array.
            if(unmap.find(Sum - goal) != unmap.end())
            {
                count = count + unmap[Sum - goal];
            }

            // increment frequency count of Sum in our map
            unmap[Sum]++;
        }

        return count;
    }
};