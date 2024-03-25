
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
    // global variable accessible for all functions
    ListNode *current = NULL;

    // 1000: imaginary address value assigned to 'recur' function
    bool recur(ListNode *head)
    {
        if(head == NULL)
        {
            // base value returning true after recursive calls => 1->2->2->1->NULL
            return true;
        }

        // 200: imaginary address value assigned to 'result' variable
        bool result = recur(head -> next); // recursive call to 1000

        // verifying values
        if(head -> val != current -> val)
        {
            return false;
        }
        // head retracks it path passed as a parameter when called recursively
        // while cuurent still holds original value head i.e 1st element in the list
        current = current -> next;

        return result;
    // returning result to the recursive calls and deleting function stacks created while the same recursive call
    // finall after deletion of all stacks recur() function returns final result to it's first original call
    // wef to reur(head) in isPallindrome function
    }
    

    bool isPalindrome(ListNode* head) 
    {
        // pointer initiated to head
        current = head;
        return recur(head);  // call to 1000
    }
};