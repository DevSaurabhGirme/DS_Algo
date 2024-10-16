// didn't work

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();

        // to store ends of the groups
        vector<int> ends;

        for(vector<int>& interval : intervals)
        {
            int curr_end = interval[1];
            
            if(ends.size() == 0)
            {
                ends.push_back(curr_end);
            }
            else
            {
                // interating over ends vector
                for(int i = 0; i < ends.size(); i++)
                {
                    // curr_start > end of curr_group
                    if(interval[0] > ends[i])
                    {
                        ends.push_back(curr_end);
                        break;
                    }
                }
            }
        }

        return ends.size();
    }
};