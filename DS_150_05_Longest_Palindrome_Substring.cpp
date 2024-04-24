//without memoization

class Solution {
public:
    // traditional check palindrome function with recursion
    bool Solve(string &s, int i, int j)
    {
        if(i >= j)
        {
            return true;
        }

        if(s[i] == s[j])
        {
            return Solve(s, i+1, j-1);
        }

        return false;
    }   

    string longestPalindrome(string s) 
    {
        int n = s.length();

        int maxLen = INT_MIN;
        int sp = 0;

        // travelling entire string using two pointers
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                // if palindrome
                if(Solve(s, i, j) == true)
                {
                    if(j-i+1 > maxLen)
                    {
                        // length of palindrome
                        maxLen = j-i+1;
                        // start point of palindrome
                        sp = i;
                    }
                }
            }
        }
        return s.substring(sp,maxLen);
    }
};