/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(root == NULL)
        {
            return false;
        }

        return correspond(head, root) || isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }

    bool correspond(ListNode* head, TreeNode* root)
    {
        // linked list traversed successfully
        if(head == NULL)
        {
            return true;
        }

        if(root == NULL)
        {
            return false;
        }

        // values of list node and treenode doesn't match
        if(head -> val != root -> val )
        {
            return false;
        }

        // traversing left subtree
        bool left = correspond(head -> next, root -> left);
        // traversing right subtree
        bool right = correspond(head -> next, root -> right);
        
        
        return left || right;
    }
};