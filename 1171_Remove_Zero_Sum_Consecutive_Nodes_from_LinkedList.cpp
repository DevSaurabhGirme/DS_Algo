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
#include <cstddef>
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        int preSum = 0;
        // map to store sum and the address of the node
        unordered_map<int, ListNode*> unmap;    
    
        // dummynode to store value of head while returning new head and also for storing initial prefix value in map
        ListNode* dNode = new ListNode(0);
        dNode -> next = head;
        
        // initialization of map with int = 0 at node dNode as ListNode
        unmap[0] = dNode;

        while(head != NULL)
        {
            // running sum of nodes' value
            preSum = preSum + head -> val;

            // if we find this sum in the map until the end
            if(unmap.find(preSum) != unmap.end())
            {
                // ListNode holding address of 1st node in the list as well as the map wef head
                ListNode* start = unmap[preSum];
                // a temparory variable to travel the list and to uplook the map
                ListNode* temp = start;

                // using the predum wef the runnig sum to delete the unwanted nodes
                int Sum = preSum;

                while(temp != head)
                {
                    temp = temp -> next;
                    Sum = Sum + temp -> val;

                    if(temp != head)
                    {
                        unmap.erase(Sum);
                    }
                }
                // at last point to the first node after deleting unwanted nodes using the head's last updated value
                start -> next = head-> next;          
            }
            // if sum not found add to the map at the head it was found at
            else
            {
                unmap[preSum] = head;
            }

            head = head -> next;
        }

        // finally return new head by retrieving stored value of head in the dummy node
        return dNode -> next;

    }
};