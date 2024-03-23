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
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        // we use stack to store our nodes which we will later
        // use it to- kind of reverse the second half of list
        stack<ListNode *> stk;

        // pointer pointing to head
        ListNode *current = head;

        while(current != NULL)
        {
            stk.push(current);
            current = current -> next;
        }

        // finding mid of the stack
        int k = stk.size()/2;

        // retrieving value of current
        current = head;
        ListNode *temp = NULL;
        
        // pop top k nodes referencing to same logic as of rversing the scond half of the list
        // and then reordering it
        while(k > 0)
        {
            Listnode *topNode = stk.top();
            stk.pop();

            temp = current -> next;

    /*1*/   current -> next = topNode;
    /*2*/   topNode -> next = temp;
            
            current = temp;
        }
        // steps 1 and 2 creates a cycle in the list, To tackle this situation we use~
        // since current always stops on the last node we have to point it to NULL;
        current -> next = NULL;
    }
};