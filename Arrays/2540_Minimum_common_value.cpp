//worked perfectly

class Solution {
public:
    int getCommon(vector<int>& Arr1, vector<int>& Arr2) 
    {
        int iSize = Arr1.size();
        int jSize = Arr2.size();
        
        int i = 0; //for Arr1
        int j = 0; //for Arr2
        
        while(i < iSize && j < jSize) {
            if(Arr1[i] == Arr2[j]) 
            {
                return Arr1[i];
            }
            else if(Arr1[i] < Arr2[j]) 
            {
                i++;
            }
            else 
            {
                j++;
            }
        }
        
        return -1;
    }
};