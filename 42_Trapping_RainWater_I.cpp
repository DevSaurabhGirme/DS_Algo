class Solution {
public:

    vector<int> getleftMaxArray(vector<int>& height, int& n)
    {
        vector<int> left_Max(n);

        left_Max[0] = height[0];

        for(int i = 1; i < n; i++)
        {
            left_Max[i] = max(left_Max[i-1], height[i]);
        }

        return left_Max;
    }


    vector<int> getrightMaxArray(vector<int>& height, int& n)
    {
        vector<int> right_Max(n);

        right_Max[n-1] = height[n-1 ];

        for(int i = n-2; i >= 0; i--)
        {
            right_Max[i] = max(right_Max[i+1], height[i]);
        }

        return right_Max;
    }

    int trap(vector<int>& height) 
    {
        int n = height.size();

        vector<int> left_Max = getleftMaxArray(height, n);
        vector<int> right_Max = getrightMaxArray(height, n);
    
        int water= 0;

        for(int i = 0; i < n; i++)
        {
            // calculating water stored on ith building
            int h = min(left_Max[i] , right_Max[i]) - height[i];

            water = water + h;
        }

        return water;
    }
};