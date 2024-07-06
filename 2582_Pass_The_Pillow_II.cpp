// T.C = O(1)   S.C = O(1)

class Solution {
public:
    int passThePillow(int n, int time) {
        
        int half = time / (n-1);
        int timeleft = time % (n-1);

        if(half % 2 == 0)
        {
            // even
            // at starting position or somewhere around 1st half of roundtrip
            return timeleft + 1;
        }
        else
        {
            return n- timeleft;
        }
        
        return -1;
    }
};