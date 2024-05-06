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

// T.C = O(n)   S.C = O(n)

class Solution {
public:
    ListNode* removeNodes(ListNode* head) 
    {
        // stack to store nodes of the list to be accessed in reverse order
        stack<ListNode*> stk;

        // temporary pointer to the head of the list
        ListNode* temp = head;

        // push all the nodes of the list to the stack
        while(temp != NULL)
        {
            stk.push(temp);
            temp = temp->next;
        }

        ListNode* curr = NULL;
        // retreive top node from stack and pop it
        curr = stk.top();
        stk.pop();
        
        // variable to hold maximmum value
        int maxNode = curr -> val;

        // new list
        ListNode* newHead = new ListNode(curr -> val);
        
        while(!stk.empty())
        {
            curr = stk.top();
            stk.pop();

            // compare current value and maximum value
            if(curr -> val < maxNode)
            {
                continue;
            }
            // new maximmum found
            else
            {
                ListNode *newNode = new ListNode(curr -> val);
                newNode -> next = newHead;
                newHead = newNode;
                maxNode = curr -> val;
            }
        }

        return newHead;
    }
};