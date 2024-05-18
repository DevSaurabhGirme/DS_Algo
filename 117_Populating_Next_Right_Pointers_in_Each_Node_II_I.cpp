/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        Node *head = NULL;       // head of next level
        Node *previous = NULL;   // previous node for next level nodes
        Node *curr_node = root;  // current node current level

        // outer loop of BFS
        while(curr_node != NULL)
        {
            // iterating current level compltely
            while(curr_node != NULL)
            {
                // left children
                if(curr_node -> left != NULL)
                {
                    // first node of new level
                    if(previous == NULL)
                    {
                        head = curr_node -> left;
                    }
                    else
                    {
                        previous -> next = curr_node -> left;
                    }
                    previous = curr_node -> left;
                }
            
                // right children
                if(curr_node -> right != NULL)
                {
                    // first node of new level
                    if(previous == NULL)
                    {
                        head = curr_node -> right;
                    }
                    else
                    {
                        previous -> next = curr_node -> right;
                    }
                    previous = curr_node -> right;
                }

                curr_node = curr_node -> next;
            }

            curr_node = head;
            head = NULL;
            previous = NULL;
        }

        return root;
    }
};