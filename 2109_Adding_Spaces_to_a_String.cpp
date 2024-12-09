// T.C = O(m+n)     S.C = O(m)

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        int m = s.length();
        int n = spaces.size();

        string modified = "";

        //to traverse in spaces vector
        int j = 0;

        for(int i = 0; i < m; i++) 
        {
            // index found where space is to be added
            if(j < n && i == spaces[j]) 
            {
                modified += " ";
                j++;
            }

            modified += s[i];
        }

        return modified;
    }
};