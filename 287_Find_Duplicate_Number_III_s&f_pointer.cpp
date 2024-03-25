class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // slow pointer 
        int s = nums[0];
        // fast pointer
        int f = nums[0];

        // index 0's vlaue
        s = nums[s];
        // index 0's then 1's value 
        f = nums[nums[f]];

        // detecting cycle
        while(s != f)
        {
            s = nums[s];
            f = nums[nums[f]];
        }

        // cycle found hence reset slow pointer to integer of index 0
        s = nums[0];

        // finding integer causing cycle
        // which is also our integer occuring more than once
        while(s != f)
        {
            s = nums[s];
            f = nums[f];
        }

        return s; // f

    }
};