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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == NULL)
        {
            return list2;
        }    
        if(list2 == NULL)
        {
            return list1;
        }    
    
        // sorted is a pointer of type ListNode currently pointing to NULL
        ListNode *sorted = NULL;

        if(list1 -> val < list2 -> val)
        {
            sorted = list1;
            // recursive call
            sorted -> next = mergeTwoLists(sorted -> next, list2);
        }
        else
        {
            sorted = list2;
            // recursive call
            sorted -> next = mergeTwoLists(list1, sorted -> next);
        }

        return sorted;
    }
};