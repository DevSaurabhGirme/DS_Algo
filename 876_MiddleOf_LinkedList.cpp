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

// again works perfectly
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        //counter for our loops
        int Count = 0;

        // two temporary variables : one to store head and another to store address of required output in our last if condition
        ListNode *temp = head;
        ListNode *temp1 = head;

        // traverse through the list to count number of nodes
        while (temp != NULL)
        {
            Count++;
            temp = temp -> next;
        }
        // reseting value
        temp = head;

        // if even number of nodes
        if(Count % 2 == 0)
        {
            int iCnt = Count/2;
            // traverse the list until half and return the middle node
            for(int i = 1; i <= iCnt; i++)
            {
                temp = temp -> next;
            }
            return temp;
        }

        // if odd number of nodes
        if(Count % 2 != 0)
        {
            // traverse until second middle and return the same
            int iCnt = Count/2+1;
            for(int i = 1; i <= iCnt-1; i++)
            {
                temp = temp -> next;
            }
            // storing the output in temporary variable
            temp1 = temp;
        }
    
        return temp1;
    }
};