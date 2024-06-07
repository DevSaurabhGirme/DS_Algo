class Solution {
public:

    string findRoot(string &word, unordered_set<string>& Roots_set)
    {
        // iterating to find root
        for(int len = 1; len <= word.length(); len++)
        {
            string root = word.substr(0, len);

            if(Roots_set.count(root))
            {
                return root;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        // to store roots
        unordered_set<string> Roots_set(begin(dictionary), end(dictionary));

        // sS now stores sentence and is ready to provide each word
        stringstream sS(sentence);
        string word;

        string result;

        while(getline(sS, word, ' '))
        {
            result += findRoot(word, Roots_set) + " ";
        }

        // removing extra space
        result.pop_back();

        return result;
    }
};