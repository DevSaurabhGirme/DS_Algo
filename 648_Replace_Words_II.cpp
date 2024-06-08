class Solution {
public:
    struct trieNode {
        trieNode *children[26];

        // denoting end of word or prefix
        bool isEnd;
    };

    /// node creation ///  
    trieNode *getNode(){
        trieNode *newNode = new trieNode();
        newNode -> isEnd = false;

        // initializing array in the node with NULL
        for(int i = 0; i < 26; i++)
        {
            newNode -> children[i] = NULL;
        }

        return newNode;
    }

    /// inserting a node ///
    // root of our trie structure
    trieNode *root;

    void insertNode(string word){
        // traveler is a pointer of type trieNode currently initialized to root
        trieNode *traveler = root;

        for(int i = 0; i < word.length(); i++)
        {
            // finding index
            int Idx = word[i] - 'a';

            if(traveler -> children[Idx] == NULL)
            {
                traveler -> children[Idx] = getNode();
            }

            // going to this next node
            traveler = traveler -> children[Idx];
        }

        // inserted entire word
        traveler -> isEnd = true;
    }

    // searching the word

    string searchPrefix(string word)
    {
        // engine is a pointer of type trieNode currently initialized to root
        trieNode *engine = root;

        for(int i = 0; i < word.length(); i++)
        {
            int Idx = word[i] - 'a';

            // word not found 
            if(engine -> children[Idx] == NULL)
            {
                return word;
            }

            // traversing further
            engine = engine -> children[Idx];
        
            if((engine -> isEnd) != NULL)
            {
                // return shortest root for the word to be replaced
                return word.substr(0, i+1);
            }
        }

        // root for word not found
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        // creating node as root;
        root = getNode();

        // inserting nodes in our trie structure 
        for(string &root_word : dictionary)
        {
            insertNode(root_word);
        }

        // sS holds our sentence now
        stringstream sS(sentence);

        string word;
        string result;

        while(getline(sS, word, ' '))
        {
            result += searchPrefix(word) + " ";
        }

        // remove trailing space
        result.pop_back();

        return result;
    }
};