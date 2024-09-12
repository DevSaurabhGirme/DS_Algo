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
// T.C = O(n)   S.C = O(n)   

class Solution {
public:
    //////// calculating GCD ////////
    int calculateGCD(int a, int b) 
    {
        while (b != 0) 
        {
            int temp = b;
        
            b = a % b;
            a = temp;
        }
        
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        // base case
        if(head == NULL || head -> next == NULL) 
            return head;

        // Recursively call further nodes
        ListNode* temp = insertGreatestCommonDivisors(head -> next);

        // Create a new node with the GCD of current and next node values
        ListNode* gcdNode = new ListNode(calculateGCD(head->val, head->next->val));

        // Inserting the new node between the current node and the next node
        gcdNode -> next = temp;
        head -> next = gcdNode;

        // Return the current node
        return head;
    }
};