// T.C = O(n * len(words))      S.C = O(n * len(words))

class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        int n = words.size();

        // to store final common letters
        vector<string> common;

        // to store and update minimum frequency of common letters
        vector<int> count(26, INT_MAX);

        for(string &word : words)
        {
            vector<int> temp(26, 0);
            
            // populate temp array letter frequency 
            for(char &ch : word)
            {
                temp[ch - 'a']++;
            }

            // update count with minimum frequency
            for(int i = 0; i < 26; i++)
            {
                count[i] = min(count[i], temp[i]);
            }
        }


        for(int i = 0; i < 26; i++)
        {   
            int cnt = count[i];

            while(cnt != 0)
            {
                // generating a string and adding to result
                common.push_back(string(1, i+'a'));
                cnt--;
            } 
        }

        return common;
    }
};