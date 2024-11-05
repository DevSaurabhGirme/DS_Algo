// T.C = O(n)   S.C = O(n)

class Solution {
public:
    string compressedString(string word) 
    {
        int n = word.length();

        string comp = "";

        // retrieve first character of the word
        char ch = word[0];
        // counter
        int iCnt = 1;

        for(int i = 1; i < n; i++)
        {
            // same character
            if(word[i] == ch && iCnt < 9)
            {
                iCnt++;
            }
            else
            {
                comp.push_back(iCnt + '0');
                comp.push_back(ch);

                ch = word[i];
                iCnt = 1;
            }
        }
        
        comp.push_back(iCnt + '0');
        comp.push_back(ch);
        
        return comp;
    }
};