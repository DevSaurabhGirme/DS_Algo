// T.C = O(m*n)   S.C = O(1)

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        stringstream SS(sentence);
        string token;

        int idx = 1;

        while(SS >> token)
        {
            if(token.find(searchWord) == 0)
            {
                return idx;
            }

            idx++;
        }

        return -1;
    }
};
