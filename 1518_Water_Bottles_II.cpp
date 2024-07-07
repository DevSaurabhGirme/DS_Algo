// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        // initially consumed all numBottles bottles
        int consumed = numBottles;

        int empBottles = numBottles;

        while(empBottles >= numExchange)
        {
            // new full bottles after gained after exchange
            int newFullBottles = empBottles / numExchange;

            // remaining empty bottles after exchanging full ones(batch)
            int remainingEmp = empBottles % numExchange;

            // consuming these new full bottles
            consumed += newFullBottles;

            empBottles = remainingEmp + newFullBottles;

        }
        
        return consumed;
    }
};