class Solution {
public:

    void backTrack(int i, string &currSent, string& s, vector<string> &result, unordered_set<string>& wordSet)
    {
        if(i >= s.length())
        {
            result.push_back(currSent);
            return;
        }
        
        for(int j = i; j < s.length(); j++)
        {
            string tempWord = s.substr(i, j-i+1);

            // if word is valid and present in set
            if(wordSet.count(tempWord))
            {
                string tempSent = currSent;

                if(!currSent.empty())
                {
                    currSent += " ";
                }

                // take
                currSent += tempWord;
                // recursive call
                backTrack(j+1, currSent, s, result, wordSet);
                
                // not take
                currSent = tempSent;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> result;

        string currSent = "";

        // to store availble words
        unordered_set<string> wordSet;

        for(string& word : wordDict)
        {
            wordSet.insert(word);
        }

        backTrack(0, currSent, s, result, wordSet);
        
        return result;    
    }
};