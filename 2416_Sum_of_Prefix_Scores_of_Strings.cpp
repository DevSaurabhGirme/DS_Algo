// T.C = O(n*l)     S.C = O(l*n)

struct trieNode
{
    int pCount = 0;
    trieNode *children[26];
};

class Solution {
public:
    trieNode* createTrieNode()
    {
        trieNode* newNode = new trieNode();

        for(int i = 0; i < 26; i++)
        {
            newNode -> children[i] = NULL;
        }

        newNode -> pCount = 0;
        return newNode;
    }

    void insert(string& word, trieNode* root)
    {
        trieNode* engine = root;

        for(char &ch : word)
        {
            int idx = ch - 'a';

            // no character found
            if(engine -> children[idx] == NULL)
            {
                // create a node for it
                engine -> children[idx] = createTrieNode();
            }
            // update the score
            engine -> children[idx] -> pCount += 1;
            engine = engine -> children[idx];
        }
    }

    int getScore(string& word, trieNode* root)
    {
        trieNode* engine = root;

        int score = 0;
        
        for(char &ch : word)
        {
            int idx = ch - 'a';
            // retrieving the score
            score += engine -> children[idx] -> pCount;
            // traversing down the word
            engine = engine -> children[idx];
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) 
    {
        int n = words.size();

        trieNode* root = createTrieNode();

        for(string &word : words)
        {
            insert(word, root);
        }

        // to store scores
        vector<int> answer(n);

        for(int i = 0; i < n; i++)
        {
            answer[i] = getScore(words[i], root);
        }

        return answer;
    }
};