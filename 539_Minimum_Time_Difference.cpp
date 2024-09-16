// T.C = O(n logn)  S.C = O(n)

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int> timeInMinutes(timePoints.size());
        
        // Convert times to minutes
        for (int i = 0; i < timePoints.size(); i++) 
        {
            int hr = 60 * stoi(timePoints[i].substr(0, 2));
            int min = stoi(timePoints[i].substr(3,2));
            
            timeInMinutes[i] = hr + min;
        }

        // Sort time in ascending order
        sort(timeInMinutes.begin(), timeInMinutes.end());

        // Find minimum difference across adjacent elements
        int minDiff = INT_MAX;

        for (int i = 0; i < timeInMinutes.size() - 1; i++) 
        {
            minDiff = min(minDiff, timeInMinutes[i + 1] - timeInMinutes[i]);
        }

        // Consider the circular difference between last and first element
        // 24 * 60 = 1440 
        // total minutes in a day - (summation of timeat index 0 and n-1)
        minDiff = min(minDiff, 1440 - timeInMinutes.back() + timeInMinutes.front());

        return minDiff;
    }
};