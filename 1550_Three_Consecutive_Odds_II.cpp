class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        int oddCount = 0;
        
        for (int i = 0; i <= arr.size() - 3; ++i) 
        {
            if((arr[i] & 1) && (arr[i+1] & 1) && (arr[i+2] & 1)) 
            {
                return true;
            }
        }
        
        return false;
    }
};