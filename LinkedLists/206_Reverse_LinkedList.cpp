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
    ListNode* reverseList(ListNode* head) 
    {
        // address pointers to hold new 'next' and 'previous' node's address
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(head != NULL)
        {
                // address of next node in original list becomes head at last in sequence
        /*1*/    next = head -> next;
                // new next for upcomming node in reversed list
        /*2*/    head -> next = prev;
                // new head pointer of our reversed list
        /*3*/    prev = head;
                // loop condition
        /*4*/    head = next;
        }
        // return new head
        return prev;
    }
};