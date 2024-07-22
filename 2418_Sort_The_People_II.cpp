// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        unordered_map<int, string> final;

        int n = names.size();

        for(int i = 0; i < n; i++)
        {
            final[heights[i]] = names[i];
        }

        // sort in descending order based on height
        // sort(final.rbegin(), final.rend());
        sort(rbegin(heights), rend(heights));

        // retrieve and update names based on decreasing height
        for(int i = 0; i < n; i++)
        {
            names[i] = final[heights[i]];
        }

        return names;

    }
};