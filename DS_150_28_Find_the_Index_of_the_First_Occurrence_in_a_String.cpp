class Solution {
public:
    int strStr(string S1, string S2) 
    {
        // S1 = haystack S2 = needle

        int s1len = S1.length();
        int s2len = S2.length();

        // avoid finding needle in haystack if needle gets bigger than haystack
        for(int i = 0; i <= s1len-s2len; i++)
        {
            for(int j = 0; j < s2len; j++)
            {
                if(S1[i+j] != S2[j])
                {
                    break;
                }

                // if we traverse till end of needle string means we found it
                if(j == s2len - 1)
                {
                    return i;
                }
            }
        }
        // didn't found
        return -1;
    }
};