class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> charArr(26,0);    
    
        for(int i = 0; i < tasks.size(); i++)
        {
            char ch = tasks[i];
            charArr[ch - 'A']++;
        }

        int interval = 0;

        priority_queue<int> pq; // by-default implemented as max heap
        // it means that the task with the highest frequency will be at the top of the priority queue.

        for(int i = 0; i < 26; i++)
        {
            // store frequency of elements who has greater than 0 in our vector
            if(charArr[i] > 0)
            {
                pq.push(charArr[i]);
            }
        }

        while(pq.size() > 0)// pq is non-empty
        {
            vector<int> temp;
            // start processing from task 1 wef top priority task
            for(int i = 1; i <= n+1; i++)
            {
                if(pq.size() > 0)
                {
                    // retrieve the element at the top of the pq
                    int freq = pq.top();
                    // remove element from top of pq
                    pq.pop();
                    // decrement frequency of the task we just processed
                    freq--;
                    // store it in the temp vector which keeps track of updated frequencies
                    temp.push_back(freq);
                }
            }

            // placing back the task's frequency into our priority queue
            for(int &f : temp)
            {
                if(f > 0)
                {
                    pq.push(f);
                }
            }

            // when our pririty queue becomes zero
            if(pq.size() == 0)
            {
                // add up the interval count updated while processing the tasks
                interval = interval + temp.size();
            }
            else
            {
                interval = interval + (n+1);
            }
        }

        return interval;
    
    }
};