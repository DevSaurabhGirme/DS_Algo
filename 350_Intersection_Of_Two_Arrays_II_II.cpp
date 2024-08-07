// T.C = O(n + nlogn) S.C = O(1)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        int m = nums2.size();

        // to store intersection array
        vector<int> result;

        int i = 0;
        int j = 0;

        while(i < n && j < m)
        {
            if(nums1[i] == nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
                j++;
            }

            else if(nums1[i] > nums2[j])
            {
                j++;
            }
            
            else
            {
                i++;
            }
        
        }

        return result;

    }
};