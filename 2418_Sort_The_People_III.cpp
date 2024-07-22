// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        map<int, string> final;

        int n = names.size();

        for(int i = 0; i < n; i++)
        {
            final[heights[i]] = names[i];
        }

        // retrieve and update names
        int i = 0;
        for(auto it = final.rbegin(); it != final.rend(); it++)
        {
            names[i] = it -> second;;
            i++;
        }

        return names;

    }
};