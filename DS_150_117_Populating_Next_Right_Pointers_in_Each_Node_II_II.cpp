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

// T.C = O(n)   S.C = O(n)

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == NULL)
        {
            return root;
        }

        // queue to store nodes of each level
        queue<Node*> level_que;

        // level 1 = root
        level_que.push(root);

        Node* prev_node;

        // level
        while(!level_que.empty()) 
        {
            int n = level_que.size();
            prev_node = NULL;

            // processing all nodes in the current level
            while(n--)
            {
                Node* curr_node = level_que.front();
                level_que.pop();

                if(prev_node != NULL) 
                {
                    prev_node->next = curr_node;
                }

                // pushing children into que
                if(curr_node -> left != NULL)
                {
                    level_que.push(curr_node -> left);
                }

                if(curr_node -> right != NULL)
                {
                    level_que.push(curr_node -> right);
                }

                // current node becomes previous node for next iteration
                prev_node = curr_node;

                
            }
        }
        return root;
    }
};