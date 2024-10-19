// S.C = O(n)   T.C = O(n)

class Solution {
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);
        int n = s.length();

        // stores index of largest digit right of current digit
        vector<int> maxToRight(n);    
        
        maxToRight[n-1] = n-1;
        // populating the maximum array
        for(int i = n-2; i >= 0; i--)
        {
            int maxToRightIdx = maxToRight[i+1];
            int maxToRightEle = s[maxToRightIdx];

            maxToRight[i] = (s[i] > maxToRightEle) ? i : maxToRightIdx;

        }
        
        for(int i = 0; i < n; i++)
        {
            // retrieving largest digit
            int maxToRightIdx = maxToRight[i];
            int maxToRightEle = s[maxToRightIdx];

            // comparing current digit
            if(s[i] < maxToRightEle)
            {
                swap(s[i], s[maxToRightIdx]);
                return stoi(s);
            }

        }

        return num;
    }
};
