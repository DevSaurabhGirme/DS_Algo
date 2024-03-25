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

// This is recursion method where we wouldn't need to reverse any part of the list

class Solution {
public:

    // global variable/pointer
    ListNode *current = NULL;

    // user-defined function which will be called recursively
    // 1000: imaginary address for better understanding
    void recur(ListNode *head)
    {
        // head -> []
        if(head == NULL)
        {
            return;
        }
        recur(head -> next); // recursive call to 1000;

        ListNode *temp = NULL;

/*step1*/  temp = current -> next;
        
        // current / head -> []
        if(current -> next == NULL)
        {
            return;
        }
        // in case of odd number of nodes where
        // recursive function's retracing head and forward moving 'current'
        // points to same node which is usually the last to be processed
        else if(head == current)
        {
            head -> next = NULL;
            return;
        }

/*s2*/  current -> next = head;
        
        //head -> next = temp;
        
        if(temp == head)
        {
/*s3*/      head -> next = NULL;
        }
        else
        {
/*s3*/      head -> next = temp;
        }

/*s4*/  current = temp;

    }

    void reorderList(ListNode* head) 
    {
        current = head;

        recur(head);
    }
};