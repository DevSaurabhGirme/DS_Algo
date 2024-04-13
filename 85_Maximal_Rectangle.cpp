class Solution {
public:

    vector<int> getNSR(vector<int>& height)
    {
        // monotonic stack
        stack<int> stk;

        int n = height.size();
        int pseudo_Idx = n;

        vector<int> NSR(n);

        for(int i = n-1; i >= 0; i--)
        {
            if(stk.empty())
            {
                // assigning outofbound index
                NSR[i] = pseudo_Idx;
            }
            else
            {
                while(!stk.empty() && (height[stk.top()] >= height[i]))
                {
                    stk.pop();
                }

                if(stk.empty())
                {
                    // assigning outofbound index
                    NSR[i] = n;
                }
                else
                {
                    NSR[i] = stk.top();
                }
            }
            stk.push(i);
        }
        return NSR;
    }

    vector<int> getNSL(vector<int>& height)
    {
        // monotonic stack
        stack<int> stk;

        int n = height.size();

        int pseudo_Idx = -1;

        vector<int> NSL(n);

        for(int i = 0; i < n; i++)
        {
            if(stk.empty())
            {
                // assigning outofbound index
                NSL[i] = pseudo_Idx;
            }
            else
            {
                while(!stk.empty() && (height[stk.top()] >= height[i]))
                {
                    stk.pop();
                }

                if(stk.empty())
                {
                    // assigning outofbound index
                    NSL[i] = pseudo_Idx;
                }
                else
                {
                    NSL[i] = stk.top();
                }
            }
            stk.push(i);
        }
        return NSL;
    }

    int findMaxArea(vector<int>& height)
    {
        // retrieving NSR values 
        vector<int> NSR = getNSR(height);
        // retrieving NSL values
        vector<int> NSL = getNSL(height);
    
        int n = height.size();

        vector<int> width(n);

        for(int i = 0; i < n; i++)
        {
            width[i] = NSR[i] - NSL[i] - 1;
        }

        int max_Area = 0;

        for(int i = 0; i < n; i++)
        {
            int a = width[i] * height[i];

            max_Area = max(max_Area, a);
        }

        return max_Area;

    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        // rows
        int m = matrix.size();
        // columns
        int n = matrix[0].size();
    
        // 1-D array after adding multiple column's value
        vector<int> height(n);

        // add 1st row to height array
        for(int i = 0; i < n; i++)
        {
            // if (i)th element of 0th row is 1 insert 1 else 0
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }
        int max_Area = findMaxArea(height);

        // adding remaining rows to height vector
        // i.e converting x-D array into 1-D array
        for(int row = 1; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(matrix[row][col] == '0')
                {
                    height[col] = 0;
                }
                else
                {
                    height[col] += 1;
                }
            }
            max_Area = max(max_Area, findMaxArea(height));
        }
        return max_Area;
    }
};