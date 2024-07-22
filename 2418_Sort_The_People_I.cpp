// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<pair<int, string>> final;

        int n = names.size();

        for(int i = 0; i < n; i++)
        {
            final.push_back({heights[i], names[i]});
        }

        // sort in descending order based on height
        sort(final.rbegin(), final.rend());

        // retrieve and update names based on decreasing height
        for(int i = 0; i < n; i++)
        {
            names[i] = final[i].second;
        }

        return names;

    }
};