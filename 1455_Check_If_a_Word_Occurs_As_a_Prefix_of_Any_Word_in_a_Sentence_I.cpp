// T.C = O(m)   S.C = O(1)

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        int m = sentence.length();
        int n = searchWord.length();
        int idx = 1;

        int i = 0;
        while (i < m) 
        {
            int len = 0;
            bool isPrefix = true;

            // comparing current word with searchWord character by character
            while(i < m && sentence[i] != ' ') 
            {
                // character doesn't match. marked as not a prefix
                if (len < n && sentence[i] != searchWord[len]) 
                {
                    isPrefix = false;
                }
                len++;
                i++;
            }

            // if prefix marked as true and matches length of searchWord
            if(isPrefix && len >= n) 
            {
                // prefix found
                return idx;
            }

            // Move to the next word
            idx++;
            i++;
        }

        return -1; // Not found
    }
};
