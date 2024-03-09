/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        // tortoise and hare algorithm
        // we create two pointers
        ListNode *tort = head;
        ListNode *hare = head;

        // traverse through the linkedlist
        // this condition avoids thr pointer from accessing null address wef the nullpointer exception
       
        while(tort != NULL && hare != NULL && hare -> next !=  NULL && hare != NULL)
        {
            // tort moves 1 step/node at a time
            tort = tort -> next;

            // hare moves 2 steps/nodes at a time
            hare = hare-> next -> next;

            if(tort == hare)
            {
                return true;
            }
        }
        
        return false;
    }
};