// T.C = O(n) S.C = O(n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> freq;

        // to store intersection array
        vector<int> result;

        // populating the map
        for(int i = 0; i < n; i++)
        {
            freq[nums1[i]]++;
        }

        for(int i = 0; i < m; i++)
        {
            if(freq.find(nums2[i]) != freq.end())
            {
                if(freq[nums2[i]] != 0)
                {
                    result.push_back(nums2[i]);
                    freq[nums2[i]]--;                    
                }
            }
        }

        return result;

    }
};