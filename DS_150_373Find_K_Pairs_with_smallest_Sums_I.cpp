class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<P, vector<P>> max_h;

        int m = nums1.size();
        int n = nums2.size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int sum = nums1[i] + nums2[j];

                if(max_h.size() < k)
                {
                    max_h.push({sum, {i,j}});
                }

                else if(max_h.top().first > sum)
                {
                    max_h.pop();
                    max_h.push({sum, {i,j}});
                }
                else
                {
                    // avoid computing for further integers
                    break;
                }

            }
        }

        vector<vector<int>> result;

        while(max_h.empty())
        {
            P pair = max_h.top();
            max_h.pop();

            int i = pair.second.first;
            int j = pair.second.second;

            result.push_back({nums[i], nums[j]});
        }
    
        return result;
    }
};