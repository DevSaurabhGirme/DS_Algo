
class Solution {
public:
    string compressedString(string word) 
    {
        int n = word.length();

        string comp = "";

        int i = 0;
        while(i < n)
        {
            int iCnt = 0;
            char ch = word[i]; 

            while(i < n && iCnt < 9 && word[i] == ch)
            {
                iCnt++;
                i++;
            }

            comp += to_string(iCnt) + ch;
        }
        
        
        return comp;
    }
};