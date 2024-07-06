// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int passThePillow(int n, int time) {
        // pillow position
        int i = 1;
        // direction(l to r / r to l)
        int dir = 1;

        while(time > 0)
        {
            if(i + dir >= 1 && i + dir <= n)
            {
                i += dir;
                time--;
            }
            else
            {
                // changing the direction
                dir *= -1;
            }
        }
        
        return i;
    }
};