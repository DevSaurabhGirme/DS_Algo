class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();

        if(n % groupSize != 0)
        {
            return false;
        }

        map<int, int> ordmap;

        for(int &num : hand)
        {
            ordmap[num]++;
        }
        
        while(!ordmap.empty())
        {
            int curr_int = ordmap.begin() -> first;

            for(int i = 0; i < groupSize; i++)
            {
                if(ordmap[curr_int + i] == 0)
                {
                    return false;
                }

                ordmap[curr_int + i]--;

                if(ordmap[curr_int + i] < 1)
                {
                    ordmap.erase(curr_int+i);
                }
            }
        }
        return true;
    }
};