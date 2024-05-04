// T,C = O(nlogn)   S.C = O(1)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int l = 0;
        int r = people.size() - 1;

        sort(people.begin(), people.end());

        int boatCount = 0;

        while(l <= r)
        {
            if(people[l] + people[r] <= limit)
            {
                boatCount++;
                l++;
                r--;
            }
            else
            {
                boatCount++;
                r--;
            }
        }

        return boatCount;
    }
};