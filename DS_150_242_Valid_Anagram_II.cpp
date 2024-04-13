// using unordered_map
// T.C = O(m+n)     S.C = O(n) where n = 26

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // map to keep count of frequency of characters
        unordered_map<char, int> alpha;

        // iterating over s
        for(int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            alpha[ch]++;
        }

        // iterating over t
        for(int i = 0; i < t.size(); i++)
        {
            // retrieving the charater
            char ch = t[i];

            if(alpha[ch] > 0)
            {
                alpha[ch]--;
            }
            else
            {
                return false;
            }
        }
        
        // verify whether map is empty
        for(auto it : alpha)
        {
            if(it.second != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};