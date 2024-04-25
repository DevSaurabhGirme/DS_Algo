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
    
        // head is pointer of type ListNode currently pointing to obj ListNode initialized to 0
        ListNode *head = new ListNode(-1);
        // temp is a pointer of type ListNode currently pointing to head
        ListNode *temp = head;

        while(list1 != NULL && list2 != NULL)
        {
            if(list2 -> val > list1 -> val)
            {
                temp -> next = list1;
                list1 = list1 -> next;
            }
            else
            {
                temp -> next = list2;
                list2 = list2 -> next;
            }

            temp = temp -> next;
        }

        if(list1 == NULL)
        {
            temp -> next = list2;
        }
        else
        {
            temp -> next = list1;
        }
        return head -> next;
    }
};