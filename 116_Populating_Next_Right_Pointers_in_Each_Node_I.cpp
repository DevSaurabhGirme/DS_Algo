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
        if(root == NULL)
        {
            return NULL;
        }

        Node *curr_level = root;
        Node *ptr = NULL;

        // traversing left subtree
        while(curr_level -> left != NULL)
        {
            ptr = curr_level;

            // traversing right subtree
            while(ptr != NULL)
            {
                // populating *next with corresponding right node
                ptr -> left -> next = ptr -> right;

                if(ptr -> next != NULL)
                {
                    // assigning the right subtree's left to left subtree's right's next 
                    ptr -> right -> next = ptr -> next -> left;
                }
                ptr = ptr -> next;
            }

            curr_level = curr_level -> left;
        }
        return root;
    }
};