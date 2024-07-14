class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        int n = positions.size();

        vector<int> actualIdx(n);

        for(int i = 0; i < n; i++)
        {
            actualIdx[i] = i;
        }

        // auto lambda = [](int i , int j) {
        //     if(positions[i] < positions[j])
        //     {
        //         return true;
        //     }
        //     return false;

        // };

        auto lambda = [&positions](int i , int j) {
            return positions[i] < positions[j];
        };

        sort(begin(actualIdx), end(actualIdx), lambda);

        vector<int> result;
        stack<int> stk;

        for(int &currIdx : actualIdx)
        {
            if(directions[currIdx] == 'R')
            {
                stk.push(currIdx);
            }
            else
            {
                while (!stk.empty() && healths[currIdx] > 0)
                {
                    int topIdx = stk.top();
                    stk.pop();

                    if(healths[topIdx] > healths[currIdx])
                    {
                        healths[topIdx] -= 1;
                        healths[currIdx] = 0;
                        stk.push(topIdx);
                    }
                    else if(healths[topIdx] < healths[currIdx])
                    {
                        healths[currIdx] -= 1;
                        healths[topIdx] = 0;        
                    }
                    else{
                        healths[currIdx] = 0;
                        healths[topIdx] = 0;
                    }
                }
                
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(healths[i] > 0)
            {
                result.push_back(healths[i]);
            }
        }

        return result;
    
    }
};  