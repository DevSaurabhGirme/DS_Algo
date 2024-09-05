#include <string>

// T.C = O(Obs*log(Obs) + Steps*log(Obs))   S.C = O(Obs)

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        // set to store obstacles
        set<string> obstacle_set;
    
        for(vector<int> obs : obstacles)
        {
            string obstacle = to_string(obs[0]) + "+" + to_string(obs[1]);
            obstacle_set.insert(obstacle);
        }
        
        //                                west , north, east ,  south
        vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}}; 

        int dir = 1; // north 
        // 0: west, 1: north, 2: east, 3: south
        
        // current coordinates of the robot
        int x = 0;
        int y = 0;

        // euclidians distance
        int maxDist = 0;
        
        // following the commands
        for(int cmd : commands)
        {
            // turn left
            if(cmd == -2)
            {
                // west
                if(dir == 0)
                    // turn towards south 
                    dir = 3;
                else
                    // remaining directions
                    dir--;
            }
            // turn right
            else if(cmd == -1)
            {    
                dir = (dir + 1) % 4;
            }
            // walking
            else
            {
                // walk k units
                int k = cmd;

                for(int i = 0; i < k; i++)
                {
                    // new coordinates in dir dirdction
                    int x_ = x + directions[dir][0];
                    int y_ = y + directions[dir][1];
                    
                    string obstacle = to_string(x_) + "+" + to_string(y_);
                    
                    // check if current coordinates are obstacle
                    if(obstacle_set.find(obstacle) != obstacle_set.end())
                    {
                        // obstacle found
                        break;
                    }

                    // new position
                    x = x_;
                    y = y_;
                    
                    // Euclidian distance
                    maxDist = max(maxDist, x*x + y*y);
                
                }
            }
        } 

        return maxDist;
    }
};