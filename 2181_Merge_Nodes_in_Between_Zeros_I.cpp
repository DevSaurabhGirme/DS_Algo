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
        ListNode* temp1 = head -> next;
        ListNode* temp2 = temp1;

        while(temp2 != NULL)
        {
            int sum = 0;

            while(temp2 != NULL && temp2 -> val != 0)
            {
                sum = sum + temp2 -> val;
                temp2 = temp2 -> next;
            }

            // modifing node
            temp1 -> val = sum;

            temp2 = temp2 -> next;
            //connecting to next non-zero valued node
            temp1 -> next = temp2;

            temp1 = temp1 -> next;
        }

        return head -> next;
    }
};