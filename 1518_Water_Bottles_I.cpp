// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int consumed = 0;

        while(numBottles >= numExchange)
        {
            // adding drank bottles to consumed
            consumed += numExchange;
            // reducing exchanged bottles from total bottles
            numBottles -= numExchange;

            // adding the 1 bottle to total bottles after exchanging
            // it for empty bottles
            numBottles += 1;
        }

        return consumed + numBottles;
    }
};