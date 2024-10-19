// T.C = O(n)   S.C = O(n)

class Solution {
public:
    typedef pair<int, int> P;
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<P, vector<P>> max_heap;

        if(a > 0)
            max_heap.push({a, 'a'});
        
        if(b > 0)
            max_heap.push({b, 'b'});

        if(c > 0)
            max_heap.push({c, 'c'});

        string res = "" ;

        while(!max_heap.empty())
        {
            int currCnt = max_heap.top().first;
            int currCh = max_heap.top().second;
            max_heap.pop();

            if(res.length() >= 2 && res[res.length()-1] == currCh && res[res.length()-2] == currCh)
            {
                if(max_heap.empty())
                {
                    break;
                }

                int nextCnt = max_heap.top().first;
                int nextCh = max_heap.top().second;
                max_heap.pop();

                res.push_back(nextCh);

                nextCnt--;

                if(nextCnt > 0)
                {
                    max_heap.push({nextCnt, nextCh});
                }
            }
            else
            {
                currCnt--;
                res.push_back(currCh);
            }

            if(currCnt > 0)
            {
                max_heap.push({currCnt, currCh});
            }
        }

        return res;
    }
};