// TC = O(n*maxofnums)      S.C = O(1000)    

class Solution {
public:
    bool isPrime[1000];

    void primeSieve() 
    {
        //initilizing the array
        fill(isPrime, isPrime+1000, true); 
     
        isPrime[0] = false;
        isPrime[1] = false; 
        
        for(int i = 2; i * i < 1000; i++) 
        {
            // marking multiples of prime 'i' as false
            if(isPrime[i] == true) 
            {
                for(int j = i*i; j < 1000; j += i) 
                {
                    isPrime[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) 
    {
        int n = nums.size();

        // calling te method to populate the isPrime array
        primeSieve();

        for(int i = n - 2; i >= 0; i--) 
        {
            if(nums[i] < nums[i+1]) 
            {
                continue;
            }

            // nums[i] >= nums[i+1]
            // select p such that
            // nums[i-1] < nums[i]-p < nums[i+1]
            for(int p = 1; p < nums[i]; p++)
            {
                if(isPrime[p] == false) 
                {
                    continue;
                }
                // prime found
                if(nums[i] - p < nums[i+1]) 
                {
                    nums[i] -= p;
                    break;
                }
            }
            // unable to make array strictly increasing
            if(nums[i] >= nums[i+1]) 
            {
                return false;
            }
        }

        return true;
    }
};
