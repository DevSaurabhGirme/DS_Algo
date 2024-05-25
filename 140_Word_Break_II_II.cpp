class Solution {
public:

    vector<string> Memo(string &s, unordered_set<string> wordSet)
    {
        if(s.empty())
        {
            return {""};
        }

        vector<string> result;

        for(int l = 1; l <= s.length(); l++)
        {
            string curr_Word= s.substr(0, l);

            if(wordSet.count(curr_Word))
            {
                string remaining_word = s.substr(l);

                vector<string> remaining_result = Memo(remaining_word, wordSet);

                for(string &W : remaining_result)
                {
                    string toAdd = curr_Word + (W.empty() ? "" : " " + W);

                    result.push_back(toAdd);
                }
            }
        }
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        // to store availble words
        unordered_set<string> wordSet;

        for(string& word : wordDict)
        {
            wordSet.insert(word);
        }

        return Memo(s, wordSet);    
    }
};