class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        // to store frequency of words in words vector
        unordered_map<string, int> temp, persist;

        // insert frequency of words
        for(string &word : words)
        {
            persist[word]++;
        }

        int slen       = s.length();
        int wSize      = words.size();
        int wordSize   = words[0].size();
        int windowSize = wSize * wordSize;

        // to store result
        vector<int> result;

        // check for all possible windows
        for(int start = 0; start <= slen-windowSize; start++)
        {
            // reset the temporary map
            temp = persist;

            // check for all words in the window
            for(int i = 0; i < windowSize; i+=wordSize)
            {
                // check if any of the permutation of the words' strings is present in the map
                bool matched = true;
                // retrieve each word
                string currWord = s.substr(start + i, wordSize);
            
                // check the retrieved word in the map
                if(temp.find(currWord) != temp.end() && temp[currWord] != 0)
                {
                    temp[currWord]--;
                }
                else{
                    break;
                }

                // check if all words are matched
                for(auto& word : temp)
                {
                    if(word.second != 0)
                    {
                        matched = false;
                        break;
                    }
                }

                // If all words are matched, add start index to result
                if(matched == true)
                {
                    result.push_back(start);
                }
            }
        }
        return result;
    }
};