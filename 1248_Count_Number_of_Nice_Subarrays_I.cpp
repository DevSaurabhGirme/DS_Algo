// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        // keeping count of oddCnt 
        unordered_map<int, int> freq;    
    
        int result = 0;
        int oddCnt = 0;
        
        // have seen oddCnt = 0 before
        freq[oddCnt] = 1;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            // finding odd numbers
            oddCnt += (nums[i] % 2 == 0) ?  0 : 1;

            // checking if seen earlier
            if(freq.count(oddCnt - k))
            {
                // if yes then add to result
                result += freq[oddCnt - k];
            }

            freq[oddCnt]++;
        }

        return result;
    }
};