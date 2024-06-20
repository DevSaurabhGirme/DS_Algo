class Solution {
public:
    bool isPossible(int force, vector<int>& position, int m)
    {
        // 1st ball placed
        int prev = position[0];
        int ballCount = 1;

        for(int i = 1; i < position.size(); i++)
        {
            // next ball's position
            int curr = position[i];

            // current magnetic force should be more than mid force  
            if(curr - prev >= force)
            {
                ballCount++;
                // prev becomes curr for the next ball now  
                prev = curr;
            }

            if(ballCount == m)
            {
                break;
            }
        }
        return ballCount == m;
    }

    int maxDistance(vector<int>& position, int m) 
    {
        int n = position.size();

        sort(begin(position), end(position));

        int minF = 1;
        int maxF = position[n-1] - position[0];    

        int minMaxForce = 0;
        while(minF <= maxF)
        {
            int midF = minF + (maxF - minF)/2;

            if(isPossible(midF, position, m))
            {
                minMaxForce = midF;

                minF = midF + 1;
            }
            else
            {
                maxF = midF - 1;
            }
        }
        return minMaxForce;
    }
};