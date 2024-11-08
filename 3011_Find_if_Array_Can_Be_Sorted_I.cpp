// T.C = O(n^2)     S.C = O(1)

class Solution {
public:
    bool canSortArray(vector<int>& nums) 
    {
        int n = nums.size();

        bool swapped = true;

        for(int i = 0; i < n; i++) 
        {
            swapped = false;
            
            // in every pass, the max element bubbles up to right most index hence -1
            for(int j = 0; j < n - i - 1; j++) 
            {
                if(nums[j] < nums[j + 1]) 
                { 
                    //no swap required
                    continue;
                } 

                //swap is required
                else 
                {
                    // only if number of bitsets is same  
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])) 
                    {
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    }
                    // number of bitsets is different
                    else 
                    {
                        // cannot swap
                        return false;
                    }
                }
            }

            if(swapped == false) 
            {
                // no swapping was done in any pass
                // array was already sorted
                break; //no more passes are required
            }

        }

        return true;
    }
};