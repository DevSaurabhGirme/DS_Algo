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
        int prev_Val = head -> val;
        int curr_Val = head -> next -> val;
        int next_Val = 0;

        int minDist = INT_MAX;
        int prev_critical_pos = 0;    
        int first_critical_pos = 0;
    
        int i = 0;
        vector<int> result = {-1, -1};

        while(head != NULL)
        {
            prev_Val = curr_Val;
            curr_Val = next_Val;
            next_Val = head -> val;

            if(prev_Val != 0 && curr_Val != 0 && next_Val != 0 &&
                // local minima || local maxima
                ((prev_Val > curr_Val && curr_Val < next_Val) || (prev_Val < curr_Val && curr_Val > next_Val)))
            {
                // found first critical point
                if(first_critical_pos == 0)
                {
                    first_critical_pos = i;
                }
                else
                {
                    minDist = min(minDist, i - prev_critical_pos);
                    result = {minDist, i - first_critical_pos};
                }
            
                prev_critical_pos = i;
            }

            i++;
            head = head -> next;
        }

        return result;
    }
};