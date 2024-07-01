// T.C = O(n)

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        int oddCount = 0;

        for(int i = 0; i < arr.size()-2; i++)
        {
            if(arr[i] % 2 != 0)
            {
                oddCount++;
            
                if(oddCount == 3)
                {
                    return true;
                }
            }    
            else
            {
                //reset the count
                oddCount = 0;
            }
        }
        return false;
    }
};