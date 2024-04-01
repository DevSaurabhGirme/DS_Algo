// using while loop

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length();

        int i = n-1;

        while(i >= 0 && s[i] == ' ')
        {
            i--;
        }

        int lastWordLen = 0;

        while(i >= 0 && s[i] != ' ')
        {
            lastWordLen++;
            i--;
        }
    
        return lastWordlen;
    }
};