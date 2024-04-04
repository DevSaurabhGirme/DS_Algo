class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size();

        if(n == 1)
        {
            return 1;
        }

        int maxPoints = 0;

        for(int i = 0; i < n; i++)  //gives first point P1(x1, y1)
        {
            for(int j = i+1; j < n; j++)  //gives second point P2(x2, y2)
            {
                // since we require atleast 2 points to form a straight line
                // we declare that these 2 points are on the same line 
                // and now use their slope to compare with slopes of other lines formed
                int count = 2;

                //  dy = y2 - y1
                int dy = points[j][1] - points[i][1];
                //  dx = x2 - x1
                int dx = points[j][0] - points[i][0];

                //float slope = dy/dx;

                /*
                    dy/dx == dy_/dx_
                    dy*dx_ == dx*dy_
                */

               for(int k = 0; k < n; k++)
               {
                    if(k != i && k != j)
                    {
                        //  dx = x3 - x1
                        int dx_ = points[k][0] - points[i][0];
                        //  dy = y3 - y1
                        int dy_ = points[k][1] - points[i][1];
                    
                        if(dy * dx_ == dy_ * dx)
                        {
                            count++;
                        }
                    }
               }

               maxPoints = max(maxPoints, count);
            }
        }
        return maxPoints;
    }
};