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

// T.C = O(n)   S.C = O(1)

class Solution {
public:
    ListNode* doubleIt(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL)
        {
            // doubling the value
            int newValue = curr -> val * 2;

            if(newValue < 10)
            {
                // no carry over needed
                curr -> val = newValue;
            }
            else if(prev != NULL)
            {
                curr -> val = newValue % 10;

                // adding the carry
                prev -> val = prev -> val + 1;
            }
            else // we are currently on head node
            {
                ListNode* newHead = new ListNode(1);
                newHead -> next = curr;
                curr -> val = newValue % 10;
                // pointing to new head
                head = newHead;
            }

            prev = curr;
            curr = curr -> next;
        }
    
        return head;
    }

};