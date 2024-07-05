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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        ListNode *prev = head;
        ListNode* curr = head -> next;

        int curr_pos = 1;
        int prev_critical_pos = 0;    
        int first_critical_pos = 0;

        int minDist = INT_MAX;

        while(curr -> next != NULL)
        {
            if(curr -> val < prev -> val && curr -> val < curr -> next -> val
                || curr -> val > prev -> val && curr -> val > curr -> next -> val)
            {
                // first critical point
                if(prev_critical_pos == 0)
                {
                    prev_critical_pos = curr_pos;
                    first_critical_pos = curr_pos;
                }
                else
                {
                    minDist = min(minDist, curr_pos - prev_critical_pos);
                    prev_critical_pos = curr_pos;
                }
            }

            curr_pos++;
            prev = curr;
            curr = curr -> next;
        }

        if(minDist == INT_MAX)
        {
            return {-1, -1};
        }

        //     {minimumDistance, maximumDistance}
        return {minDist, prev_critical_pos - first_critical_pos};

    }
};