// T.C = O(n)     S.C = O(n)  TLE

class Solution {
public:
    void LPS(string pat, vector<int>& lps)
    {
        int m = pat.length();
        // length of previous longest prefix and suffix
        int prev_len = 0;

        lps[0] = 0;

        int i = 1;
        while(i < m)
        {
            if(pat[i] == pat[prev_len])
            {
                prev_len++;
                lps[i] = prev_len;
                i++;
            }
            else
            {
                if(prev_len != 0)
                {
                    prev_len = lps[prev_len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string shortestPalindrome(string s) 
    {
        string rever = s;

        reverse(begin(rever), end(rever));

        string temp = s + "-" + rever;

        vector<int> lps(temp.length(), 0);
        LPS(temp, lps);

        int longLpsLen = lps[temp.length()-1];

        string result = rever.substr(0, s.length() - longLpsLen);

        return result + s;
    }
};