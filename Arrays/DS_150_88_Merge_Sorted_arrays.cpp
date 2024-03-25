class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        //pointer pointing to last non-zero integer of nums1 array
        int ptr1 = m-1;

        // pointer pointing to last integer of nums2 array
        int ptr2 = n-1;

        // pointer pointing to last integer of nums1 array
        int end = m+n-1;

        // loop over nums2 array for including the edge case of nums2[0] < nums1[0]
        while(ptr2 >= 0)
        {
            if(ptr1 >= 0 && nums1[ptr1] > nums2[ptr2])
            {
                nums1[end] = nums1[ptr1];
                ptr1--;
            }
            else
            {
                nums1[end] = nums2[ptr2];
                ptr2--;
            }
            end--;
        }
    }
    
};