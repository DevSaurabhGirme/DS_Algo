class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int ptr1 = 0;
        int ptr2 = 0;

        while(ptr1 < nums.size())
        {
            if(nums[ptr1] != val)
            {
                nums[ptr2] = nums[ptr1];
                ptr2++;
            }

            ptr1++;
        }
        return ptr2;
    }
};