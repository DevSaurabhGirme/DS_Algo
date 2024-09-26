//T.C : O(m⋅d+n⋅d)      S.C : O(m⋅d)

struct TrieNode
{
    char digit;
    TrieNode* children[10];
};

class Solution {
public:
    TrieNode* createTrieNode()
    {
        TrieNode* node = new TrieNode();

        for(int i = 0; i < 10; i++)
        {
            node -> children[i] = NULL;       
        }

        return node;
    }

    void insert(int num, TrieNode* root)
    {
        TrieNode* engine = root;

        string numStr = to_string(num);

        for(char ch : numStr) 
        {
            int idx = ch - '0';

            // if no intger char found
            if(engine -> children[idx] == NULL) 
            {
                // create one
                engine -> children[idx] = createTrieNode();
            }

            // move to next int char
            engine = engine -> children[idx];
        }
    }

    int search(int num, TrieNode* root)
    {
        TrieNode* engine = root;

        string numStr = to_string(num);
        int length = 0;

        for(char ch : numStr) 
        {
            int idx = ch - '0';

            // integer character found
            if(engine -> children[idx]) 
            {
                length++;
                // move to next number
                engine = engine -> children[idx];
            }
            else
            {
                // not found
                break;
            }
        }

        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        TrieNode* root = createTrieNode();

        for(int num : arr1) 
        {
            insert(num, root);
        }

        int result = 0;
        
        for(int num : arr2) 
        {
            result = max(result, search(num, root));
        }

        return result;
    } 
};