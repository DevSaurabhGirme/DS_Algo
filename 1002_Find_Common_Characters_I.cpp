// T.C = O(n * len(words))      S.C = O(n * len(words))

class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        int n = words.size();

        // to store final common letters
        vector<string> common;

        // to store and update minimum frequency of common letters
        int count[26] = {0};

        // populate count array with first word's letter frequency 
        for(char &ch : words[0])
        {
            count[ch - 'a']++;
        }

        // populate temp array with remaining words and compare with count array
        for(int i = 1; i < n; i++)
        {
            int temp[26] = {0};

            for(char &ch : words[i])
            {
                temp[ch - 'a']++;
            }

            for(int j = 0; j < 26; j++)
            {
                // updating count array with with mininmum frequency of current letter
                count[j] = min(count[j], temp[j]);
            }
        }

        for(int i = 0; i < 26; i++)
        {
            int cnt = count[i];

            while(cnt != 0)
            {
                common.push_back(string(1, i+'a'));
                cnt--;
            }
        }

        return common;
    }
};