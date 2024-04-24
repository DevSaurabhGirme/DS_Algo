//with memoization

class Solution {
public:
    int table[1001][1001];

    // traditional check palindrome function with recursion
    bool Solve(string &s, int i, int j)
    {
        if(i >= j)
        {
            return 1;
        }

        // substring already checked
        if(table[i][j] != -1)
        {
            return table[i][j];
        }

        if(s[i] == s[j])
        {
            return table[i][j] = Solve(s, i+1, j-1);
        }

        return table[i][j] = 0;
    }   

    string longestPalindrome(string s) 
    {
        int n = s.length();

        memset(table, -1, sizeof(table));

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
        return s.substr(sp,maxLen);
    }
};