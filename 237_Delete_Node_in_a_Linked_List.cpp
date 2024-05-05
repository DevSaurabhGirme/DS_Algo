/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        // store the value of next node in current node
        node -> val = node -> next -> val;
        
        // point to (next to next) node's address 
        node -> next = node -> next -> next;    
    }
};


<<<<<<< HEAD
// basically this is just overwriting of values and the node address 
=======
// basically this is just overwriting of values and the node address
// or say we are duplicating node->next in node and then pointing node to node->next->next
// so basically we are removing node->next not node from given list
>>>>>>> origin/master
