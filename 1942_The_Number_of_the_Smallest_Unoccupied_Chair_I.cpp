// T.C = O(n^2)     S.C = O(n)

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int n = times.size();

        // to store departure time of occupied chair
        // to know which chair is currently free
        vector<int> chairs(n, -1);

        int tgFrArrTime = times[targetFriend][0];

        // sort according to arrival time
        sort(times.begin(), times.end());

        for(vector<int>& time : times)
        {
            int arr = time[0];
            int dep = time[1];

            // chairs
            for(int i = 0; i < n; i++)
            {
                // if sitting friend's departure time is 
                // < arrival time of current friend
                if(chairs[i] <= arr)
                {
                    // sitting friend left
                    // and current friend occupied the chair
                    chairs[i] = dep;

                    // returning chair number
                    if(arr == tgFrArrTime)
                        return i;

                    break;
                }
            }
        }

        return -1;

    }
};