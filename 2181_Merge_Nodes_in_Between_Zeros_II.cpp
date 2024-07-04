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

// T.C = O(n)  S.C = O(1)

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        head = head -> next;

        if(head == NULL)
        {
            return head;
        }

        ListNode* temp = head;

        int sum = 0;

        while(temp -> val != 0)
        {
            sum = sum + temp -> val;
            temp = temp -> next;
        }

        // modifing value of node
        head -> val = sum;
        // recursive call
        head -> next = mergeNodes(temp);

        return head;
    }
};