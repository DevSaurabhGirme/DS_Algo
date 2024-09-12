class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int XOR = start ^ goal;
        int flipCount = 0;

        while(XOR != 0)
        {
            // flip is required
            if(XOR & 1 == true)
            {
                flipCount++;
            }
        
            // right shift
            XOR = XOR >> 1;
        }

        return flipCount;
    }
};