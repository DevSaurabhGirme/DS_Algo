class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int size = points.size();

        sort(points.begin(), points.end());

        // a vector for comparison of start and end points with  current 'i'
        // initiated to 1st arrayelement of points vector
        vector<int> previous = points[0];

        // number of arrows required to burst balloons
        // atleast 1 will be needed as for best case and also to initiate worst case
        int count = 1;

        for(int i = 1; i < size; i++)
        {
            // depicts range of balloon for current i 
            int currentStartPoint = points[i][0];
            int currentEndPoint = points[i][1];

            // depicts range of balloon for previous i / i=0 as initiated 
            int prevStartPoint = previous[0];
            int prevEndPoint = previous[1];
            
            if(currentStartPoint > prevEndPoint)
            {
                // no overlapping of balloons
                count++;
                
                // new previous becomes current i wef current balloon
                previous = points[i];
            }
            else
            {
                // overlapping
                // overlapping region consecutive balloons
                previous[0] = max(prevStartPoint, currentStartPoint);
                previous[1] = min(prevEndPoint, currentEndPoint);
            }
        }

        return count;
    }
};