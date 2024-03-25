class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // points to unique elements
        int ptr1 = 0;
        // used for travresal and finds unique elements for ptr1 to point at
        int ptr2 = 1;

        while(ptr2 < nums.size())
        {
            // found unique element
            if(nums[ptr1] != nums[ptr2])
            {
                ptr1++;
                nums[ptr1] = nums[ptr2];
            }
            ptr2++;
        }

        // return count of elements in unique nums array
        return ptr1+1;
    }
};