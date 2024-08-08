// S.C = O(1)   T.C = O([max(rows,cols)]^2)

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
    {
        vector<vector<int>> directions = {
        //    0      1      2       3
            {0,1}, {1,0}, {0,-1}, {-1,0}
        //    E      S       W       N
        };
    
        vector<vector<int>> coordinates;

        int steps = 0;
        int dir = 0;

        coordinates.push_back({rStart, cStart});

        while(coordinates.size() < rows*cols)
        {
            if(dir == 0 || dir == 2)
            {
                steps++;
            }

            // number of steps to take
            for(int count = 0; count < steps; count++)
            {
                rStart += directions[dir][0]; // {0,_}(East)  or  {0,_}
                cStart += directions[dir][1]; // {_,1}(West)  or  {_,-1}
            
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    coordinates.push_back({rStart, cStart});
                }
            }
            // direction change
            // we iterate over directions vector in pattern => E->S->W->N
            dir = (dir+1) % 4;
        }

        return coordinates;
    }
};