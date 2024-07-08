class Solution {
public:
    struct trieNode{
        bool isEnd;
        string word;
        trieNode* children[26];
    };

    // creating a node
    trieNode* createNode()
    {
        trieNode* newNode = new trieNode();

        newNode -> isEnd = false; 
        newNode -> word = "";

        for(int i = 0; i < 26; i++)
        {
            newNode -> children[i] = NULL;
        }

        return newNode;
    }

    //  inserting given words in our trie structure
    void insert(trieNode* root, string& word)
    {
        trieNode* engine = root;

        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            // checking if character is present in our structure or not
            if(engine -> children[ch - 'a'] == NULL)
            {
                // if not create it
                engine -> children[ch - 'a'] = createNode();
            }

            // pointer moved to next character
            engine =  engine -> children[ch-'a'];
        }

        engine -> isEnd = true;
        // inserting the found word into our result vector
        engine -> word = word;
    }

    /*  Searching for the word   */
    void wordSearch(vector<vector<char>>& board, int i, int j, int m, int n, trieNode* root, vector<string>& result)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }
        // character already visited or no child
        if(board[i][j] == '$' || root -> children[board[i][j] - 'a'] == NULL)
        {
            return;
        }

        root = root -> children[board[i][j] - 'a'];
    
        if(root -> isEnd == true)
        {
            result.push_back(root -> word);
            root -> isEnd = false;
        }

        char temp = board[i][j];
        // marking as visited
        board[i][j] = '$';

        for(vector<int>& dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            wordSearch(board, new_i, new_j,  m, n, root, result);
        }
        // marking unvisited
        board[i][j] = temp;

    }

    // directions to travel from each cell
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        vector<string> result;
    
        // row
        int m = board.size();
        // column
        int n = board[0].size();    
    
        trieNode* root = createNode();

        // inserting given words in our trie
        for(string& word : words)
        {
            insert(root, word);
        }

        // traversing the grid and finding the word
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                char ch = board[i][j];

                // if current character from grid is present in the trie structure
                if(root -> children[ch-'a'] != NULL)
                {
                    wordSearch(board, i, j, m, n, root, result);
                }
            }
        }

        return result;
    }
};