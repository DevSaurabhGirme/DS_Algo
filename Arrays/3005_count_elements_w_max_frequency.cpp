// one pass solution

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        // array for storing frequencies of every element 
        vector<int> iCnt(101);

        int maxFreq = 0;
        int totalFreq = 0;

        // traverse the given array to count the occourences of each integer and store it in iCnt array
        for(int i = 0; i < nums.size(); i++)
        {
            // retrieve the integer from nums array into the variable
            int no = nums[i];
            // increment the count of occurence
            iCnt[no]++;

            // store it for future usage
            int freq = iCnt[no];

            // check if frquency of current integer is greater than maximum frequency
            if(freq > maxFreq)
            {
                // assign current frequency as maximum
                maxFreq = freq;
                // also assign total count of frequency to maximum frequency
                totalFreq = maxFreq;
                
            }
            // if frequency of current integer is equal to maximum frequency...
            else if(freq == maxFreq)
            {
                // ... just add it to totalcount of MAXIMUM FREQUENCIES wef the total count
                totalFreq = totalFreq + maxFreq;
            }
        }
        //finally return total count of maximum frequencies
        return totalFreq;
    }
};