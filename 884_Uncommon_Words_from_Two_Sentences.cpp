// T.C = O(n)    S.C = O(n)   

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        unordered_map<string, int> word_map;
        
        // to store the string
        stringstream ss1(s1);
        // to store a single word from the string
        string word = "";
        
        // extracting each word from ss1 into the 'word'
        while(ss1 >> word) 
        {
            word_map[word]++;
        }
        
        stringstream ss2(s2);        
        while(ss2 >> word)
        {
            word_map[word]++;
        }
        
        // to store the uncommon words
        vector<string> result;

        for(auto &it : word_map)
        {
            if(it.second == 1)
            {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};