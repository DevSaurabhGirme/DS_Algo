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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        // will store address of (a-1)th node
        ListNode *start = NULL;

        // will store address of (b+1)th node
        ListNode *end = list1;
    
        // temporary pointer used to travel list2
        ListNode *temp = list2;

        int i = 0;
        while(i <= b)
        {
            // found our (a-1)th node
            if(i == (a-1))
            {
                start = end;
            }
            i++;
        end = end -> next;
        }

        // pointing (a-1)th node towards list2
        start -> next = list2;

        // traversing list2 until end
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        // connecting list2's end node's next to (b+1)th node of list2
        temp -> next = end;

        // finally returning head of list1;
        return list1;
    }
};