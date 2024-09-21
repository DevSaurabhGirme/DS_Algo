// T.C = O(n^2)     S.C = O(n)  TLE

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
            if(s.substr(0, s.length() - i) == rever.substr(i))
            {
                // appending the prefix of reversed string in front of original
                return rever.substr(0, i) + s;
            }
        }

        return rever + s;
    }
};