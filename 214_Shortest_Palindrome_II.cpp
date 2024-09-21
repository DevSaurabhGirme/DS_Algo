// T.C = O(n^2)     S.C = O(n)

class Solution {
public:
    string shortestPalindrome(string s) 
    {
        string rever = s;

        // reversing the original string
        reverse(begin(rever), end(rever));

        for(int i = 0; i < s.length(); i++)
        {
            // checking if suffix of s is equal to prefix of reversed
            // using memory comparison
            if(memcmp(s.c_str(), rever.c_str() + i, s.length()-i) == 0)
            {
                return rever.substr(0, i) + s;
            }
        }

        return rever + s;
    }
};