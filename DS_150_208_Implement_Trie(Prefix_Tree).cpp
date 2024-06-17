// T.C = O(n)   S.C = O(N)

class Trie {
public:

    struct trieNode{
        bool isEnd;

        // children is an array pointer of type trieNode
        trieNode *children[26];
    };

    // creating new node say root
    // The function createNode() returns a pointer named 'newNode' 
    // which points to a newly created trieNode object
    trieNode* createNode()
    {
        trieNode * newNode = new trieNode();

        newNode -> isEnd = false;

        for(int i = 0; i < 26; i++)
        {
            newNode -> children[i] = NULL;
        }

        return newNode;
    }

    // member variable(pointer)
    // top node in the structure
    trieNode* root; 

    // constructor
    Trie() {
        // The root is a pointer variable that holds the 
        // address of the newly created 'trieNode' object
        // by calling the createNode() function
        root = createNode();
    }
    
    void insert(string word) 
    {
        // pointer pointing to root of the structure 
        trieNode* iPtr = root;

        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            // 0 <= Idx <= 25
            int Idx = ch - 'a';

            // start to access the children array in the root
            if(iPtr -> children[Idx] == NULL)
            {
                // newnode created as 'a' at Idx = 0

                // a node for character 'a' is created 
                // and children[Idx] stores address to it
                iPtr -> children[Idx] = createNode();
            }

            // pointer moved to next character
            iPtr = iPtr -> children[Idx];
        }

        iPtr -> isEnd = true;
    }
    
    bool search(string word) 
    {
        // pointer pointing to root of the structure 
        trieNode* iPtr = root;

        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            // 0 <= Idx <= 25
            int Idx = ch - 'a';

            // reached the end of tree nodes
            if(iPtr -> children[Idx] == NULL)
            {
                return false;
            }

            // pointer moved to next character
            iPtr = iPtr -> children[Idx];
        }

        // successfully reached end of the word
        if(iPtr != NULL && (iPtr -> isEnd == true))
        {
            return true;
        }

        // word not found
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        // pointer pointing to root of the structure 
        trieNode* iPtr = root;

        int i = 0;
        for(; i < prefix.length(); i++)
        {
            char ch = prefix[i];
            // 0 <= Idx <= 25
            int Idx = ch - 'a';

            // reached the end of tree nodes
            if(iPtr -> children[Idx] == NULL)
            {
                return false;
            }

            // pointer moved to next character
            iPtr = iPtr -> children[Idx];
        }

        // successfully reached end of the prefix
        if(i == prefix.length())
        {
            return true;
        }

        // prefix not found
        return false;    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */