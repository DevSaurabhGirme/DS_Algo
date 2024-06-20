class Solution {
public:

    int canMakeBouq(vector<int>& bloomDay, int mid, int k)
    {
        int bCount = 0;
        int consecCount = 0;

        for(int i = 0; i < bloomDay.size(); i++)
        {
            // flower has bloomed
            if(bloomDay[i] <= mid)
            {
                consecCount++;
            }
            else
            {
                consecCount = 0;
            }

            // required flowers collected to make a bouqet
            if(consecCount == k)
            {
                // made
                bCount++;
                // reseting to 0 for next bouqet
                consecCount = 0;
            }
        }
        return bCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();

        int startDay = 0;
        int endDay = *max_element(begin(bloomDay), end(bloomDay));

        int minDays = -1;

        while(startDay <= endDay)
        {
            int mid = startDay + (endDay - startDay)/2;

            // check whether required number of bouquets made
            if(canMakeBouq(bloomDay, mid, k) >= m)
            {
                minDays = mid;
                // decrementing in search for min days
                endDay = mid-1;
            }
            else
            {
                startDay = mid + 1;
            }
        }   
        return minDays;
    }
};