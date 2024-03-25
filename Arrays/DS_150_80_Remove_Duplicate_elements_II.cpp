class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int size = nums.size();

        // we need atlest 2 elements to comply with the problem statment
        if(size < 2)
        {
            return size;
        }

        int p1 = 2;
        int p2 = 2;
        // P1 = will iterate over the nums array
        // p2 = used to insert new element

        while(p1 < nums.size())
        {
            if(nums[p1] != nums[p2-2])
            {
                // found new integer to insert
                nums[p2] = nums[p1];
                p2++;
            }

            p1++;
        }
        return p2;
        
    }
};
