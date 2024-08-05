// T.C = O(k*log(m*n)) or O(k*log(k))   S.C = O(k)

class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<P, vector<P>, greater<P>> min_h;

        int m = nums1.size();
        int n = nums2.size();

        // smallest sum
        int sum = nums1[0] + nums2[0];

        vector<vector<int>> result;

        set<pair<int, int>> visited;

        // pushing smallest sum into heap
        min_h.push({sum, {0,0}});
        // marking as visited
        visited.insert({0,0});

        while(k > 0 && !min_h.empty())
        {
            P pair = min_h.top();
            min_h.pop();

            int i = pair.second.first;
            int j = pair.second.second;

            result.push_back({nums1[i], nums2[j]});
            k--;
        
            // pushing (i, j+1)
            if(j+1 < n && visited.find({i, j+1}) == visited.end())
            {
                min_h.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        
            // pushing (i+1, j)
            if(i+1 < m && visited.find({i+1, j}) == visited.end())
            {
                min_h.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }
        }
    
        return result;
    }
};