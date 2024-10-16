// T.C = o(n log(n))    S.C = O(n)

class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int n = times.size();
        
        // stores pair of departure time and chair number
        priority_queue<P, vector<P>, greater<P>> occupied;
    
        // stores available chairs
        priority_queue<int, vector<int>, greater<int>> freeChair;

        int tgFrArrTime = times[targetFriend][0];

        int chairNo = 0;
        sort(times.begin(), times.end());

        for(int i = 0; i < n; i++)
        {
            int arr = times[i][0];
            int dep = times[i][1];

            // departure of occupied is less than arrival
            while(!occupied.empty() && occupied.top().first <= arr)
            {
                // mark as available
                freeChair.push(occupied.top().second);

                occupied.pop();
            }

            if(freeChair.empty())
            {
                occupied.push({dep, chairNo});
                // target found
                if(arr == tgFrArrTime)
                {
                    return chairNo;
                }

                chairNo++;
            }
            else
            {
                int chAvl = freeChair.top();
                freeChair.pop();

                if(arr == tgFrArrTime)
                {
                    return chAvl;
                }

                occupied.push({dep, chAvl});
            }
        }

        return -1;
    }
};