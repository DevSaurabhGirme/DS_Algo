// T.C = O(nlogn + Nlog(N))   S.C = O(n+N)

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();

        vector<pair<int, int>> netP(n);

        for(int i = 0; i < n ;i++)
        {
            netP[i] = {capital[i], profits[i]};
        }

        // sorting based on capital
        sort(begin(netP), end(netP));
    
        priority_queue<int> pque;

        int i = 0;

        while(k--)
        {
            //          required capital <= capital in hand
            while(i < n && netP[i].first <= w){
                pque.push(netP[i].second);
                i++;
            }
            if(pque.empty())
            {
                break;
            }

            w += pque.top();
            pque.pop();
        }

        return w;
    }
};