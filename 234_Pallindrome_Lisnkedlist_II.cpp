// reversing first half while finding mid

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
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)
        {
            // [] <--> [] || [1] <--> [1]
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode *prev = NULL;

        ListNode *temp = NULL;

        // reversing the first half of the list and simultaneously finding mid-element
        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next;
            temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;// slow points to the mid element
        }

        // finding mid-element for even number of elements in the list
        if(fast != NULL)
        {
            slow = slow -> next;
        }

        // checking equality of first half of list with the other half
        //     first half        second half
        while(prev != NULL  &&  slow != NULL)
        {
            if(prev -> val != slow -> val)
            {
                return false;
            }

            prev = prev -> next;
            slow = slow -> next;
        }

        return true;
    }
};