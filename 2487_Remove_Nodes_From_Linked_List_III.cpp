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
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        ListNode* last = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return last;
    }

    ListNode* removeNodes(ListNode* head)
    {
        // first reverse given linked list
        head = reverseList(head);

        int maxNode = -1;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            maxNode = max(maxNode, curr -> val);

            if(curr -> val < maxNode)
            {
                prev -> next = curr -> next;
                ListNode* temp = curr;
                curr = curr -> next;
                delete(temp);
            }
            else
            {
                prev = curr;
                curr = curr -> next;
            }
        }
        // reverse again to form correct order
        return reverseList(head);
    }
};