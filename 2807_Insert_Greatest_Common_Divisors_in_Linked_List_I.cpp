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

        ListNode* currNode = head;
        ListNode* nextNode = head -> next;

        while(nextNode != NULL) 
        {
            int gcdValue = 0;
            // creating a new node with gcd
            ListNode* gcdNode = new ListNode(gcdValue = calculateGCD(currNode->val, nextNode->val));

            // Insert gcdNode between currNode and nextNode
            currNode -> next = gcdNode;
            gcdNode -> next = nextNode;

            // Move to the next pair of nodes
            currNode = nextNode;
            nextNode = nextNode -> next;
        }

        return head;
    }
};