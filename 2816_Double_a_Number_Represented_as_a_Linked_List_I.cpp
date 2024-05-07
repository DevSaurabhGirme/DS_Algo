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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) 
        {
            return head;
        }
        
        // recusrive call
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return last;
        
    }

    ListNode* doubleIt(ListNode* head) 
    {
        // reverse the list first
        head = reverseList(head);

        ListNode* curr = head;
        ListNode* prev = NULL;

        int carry = 0;

        while(curr != NULL)
        {
            int newValue = (curr -> val * 2) + carry;
            curr -> val = newValue % 10;

            if(newValue >= 10)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            prev = curr;
            curr = curr -> next;
        }

        if(carry != 0)
        {
            // create new node with value = carry
            ListNode* newHead = new ListNode(carry);

            // assigning new head
            prev -> next = newHead;
        }

        // again reverse the list to correct order
        return reverseList(head);
    }

};