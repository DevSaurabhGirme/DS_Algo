class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();

        int i = 0;
        int j = n-1;

        int maxWater = 0;

        while(i < j)
        {
            //  area =  width  * height of (i)th line
            int Area = (j - i) * min(height[i], height[j]);

            maxWater = max(maxWater, Area);

            // decrementing width while keeping height maximum
            if(height[i] > height[j])
            {
                j--;
            }
            else
            {
                i--;
            }

        }

        return maxWater;
    }
};