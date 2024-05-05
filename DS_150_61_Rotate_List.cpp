/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// T.C = O(n)   S.C = O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        // Check for edge cases
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        // Length of the linked list
        int LL_len = 1;

        // pointer for traversal
        ListNode *tail = head;

        // Find the length and the last node of the linked list
        while(tail->next != NULL)
        {
            tail = tail->next;
            LL_len++;
        }

        // Make the linked list circular
        tail -> next = head;

        // Calculate the effective rotation to avoid redundant rotations
        k = k % LL_len;

        // If no rotation is needed
        if (k == 0)
        {
            tail->next = NULL; // Break the circularity
            return head;
        }

        // Find the new head and break the circularity
        for(int i = 0; i < LL_len - k; i++)
        {
            tail = tail->next;
        }

        // new head
        head = tail -> next;
        // Break the circularity
        tail->next = NULL; 

        return head;
    }
};