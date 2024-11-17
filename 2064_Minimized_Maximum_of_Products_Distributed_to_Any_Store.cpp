// T.C = O(m*log(maxofquantites))   S.C = o(1)

class Solution {
public:
    // check if shops are sufficient or not
    bool isPossible(int x, vector<int>& quantities, int shops)
    {
        for(int products : quantities)
        {
            // shops -= ceil(products/x)
            shops -= (products + x - 1)/x;

            if(shops < 0)
                return false;
        }
    
        return true;
    }
    

    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int m = quantities.size();

        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());

        // final count of products to be distributed
        int count = 0;

        while (l <= r)
        {
            int mid = l + (r-l)/2;

            if(isPossible(mid, quantities, n) == true)
            {
                // possible count of products to be distributed
                count = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return count;
    }
};