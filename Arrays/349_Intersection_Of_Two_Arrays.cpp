class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result;

        int i = 0; // for nums1
        int j = 0; // for nums2

        int iSize = nums1.size();
        int jSize = nums2.size();
        
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        
        while(i < iSize && j < jSize) 
        {
            if(nums1[i] == nums2[j]) 
            {
                result.push_back(nums1[i]);

                while(i < iSize - 1 && nums1[i] == nums1[i+1])
                {
                    i++;
                }
                while(j < jSize - 1 && nums2[j] == nums2[j+1])
                {
                    j++;
                }
                    i++;
                    j++;
            }
            else if(nums1[i] < nums2[j]) 
            {
                i++;
            }
            else 
            {
                j++;
            }
        }
        return result;
    }
};