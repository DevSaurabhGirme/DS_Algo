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

class Solution 
{
    public:
    ListNode* doubleIt(ListNode* head) 
    {
        if(head->val > 4) 
        {
            // create new head
            ListNode* newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
        }
        
        // traversal pointer
        ListNode* curr = head;
        
        while(curr != NULL) 
        {    
            curr->val = (curr->val * 2)%10;
            
            if(curr->next != NULL && curr->next->val > 4) 
            {
                curr->val += 1;
            }
            
            curr = curr->next;
            
        }
        
        return head;
    }

};