class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        
        int lptr = 0;   // left pointer
        int rptr = n-1;   // right pointer

        // max buiding height on left
        int left_Max = 0;
        // max buiding height on right
        int right_Max = 0;

        // total water stored
        int water = 0;

        while(lptr <= rptr)
        {
            if(height[lptr] <= height[rptr])
            {
                if(height[lptr] >= left_Max)
                {
                    left_Max = height[lptr];
                }
                else
                {   
                    // total water = water stored on top of [lptr]th building
                    // consisering left_Max because it is the max height upto which water can be stored
                    water = water + (left_Max - height[lptr]);
                }

                lptr++;
            }
            else
            {
                if(height[rptr] >= right_Max)
                {
                    right_Max = height[rptr];
                }
                else
                {
                    // consisering right_Max because it is the max height upto which water can be stored
                    water = water + (right_Max - height[rptr]);
                }

                rptr--;
            }
        }

        return water;
    }
};