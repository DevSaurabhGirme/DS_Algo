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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        if(head == NULL)
        {
            return NULL; 
        }

        // set to store nums to be deleted
        set<int> ord_set;

        // populating the set
        for(int& num : nums)
        {
            ord_set.insert(num);
        }

        // if head itself is to be deleted
        while(ord_set.find(head -> val) != ord_set.end())
        {
            head = head -> next;
        }

        ListNode* temp = head;

        while(temp -> next != NULL)
        {
            // num to be deleted from list found in set
            if(ord_set.find(temp -> next -> val) != ord_set.end())
            {
                temp -> next = temp -> next -> next;
            }

            // advance temp when no deletion happened
            else
            {
                temp = temp -> next;
            }
        }

        return head;
    }
};