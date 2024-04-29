class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int ops = 0;

        for(int bit = 0; bit < 21; bit++) 
        {
            int XorVal = 0;

            for(int i = 0; i < nums.size(); i++) 
            {   
                // claculating bitvalue for bit'th bit of every nums element using mask of 1
                int bitVal = nums[i] & (1 << bit); 
            
                // calculating XOR of every bit at bit;th position of every nums element
                XorVal ^= bitVal;
            }

            // calculate bitvalue of k for bit'th bit 
            int kBitVal = (1<<bit) & k;

            // if bitvalue of k for bit'th bit is not equal to 
            // bitvalue of every nums element at bit'th bit
            // flip any of the bit
            if(XorVal != kBitVal)
            {
                ops++;
            }
        }   
        return ops;
    }
};