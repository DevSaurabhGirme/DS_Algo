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


// basically this is just overwriting of values and the node address 