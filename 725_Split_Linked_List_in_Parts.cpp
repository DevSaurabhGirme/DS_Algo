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
// T.C = O(k+n)     S.C = O(k)

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        // number of nodes in the linked list
        int n = 0;

        // pointer pointing to head
        ListNode* curr = head;

        // calculating number of nodes in the list
        while (curr != NULL)
        {
            n++;
            curr = curr -> next;
        }

        // nodes in each k parts
        int main = n / k;
        // parts with extra 1 node(element)
        int ext = n % k;

        // reassigning 
        curr = head;
        ListNode* prev = NULL;
        
        // vector to store the parted list
        vector<ListNode*> partedArr(k, NULL);

        // splitting the list
        for(int i = 0; curr != NULL && i < k; i++)
        {
            partedArr[i] = curr;

            // considering the supposed n/k nodes while deciding to consider the extra ones or not
            for(int j = 1; j <= main + (ext > 0 ? 1 : 0); j++)
            {
                prev = curr;
                curr = curr -> next;
            }

            // breaking the connection
            prev -> next = NULL;            
            ext--;
        }

        return partedArr;
    }
};