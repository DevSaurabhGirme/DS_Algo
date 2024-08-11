// T.C = O(logn)    S.C = O(n)

class MedianFinder {
public:
    priority_queue<int> max_h;
    priority_queue<int, vector<int>, greater<int>> min_h;    

    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(max_h.empty() || num < max_h.top())
        {
            max_h.push(num);
        }
        else
        {
            min_h.push(num);
        }

        // like if min_h contains 2 elements and max_h 4
        // here     4   >   2 (+1)
        if(max_h.size() > min_h.size()+1)
        {
            min_h.push(max_h.top());
            max_h.pop();
        }
        // like if min_h contains 4 elements and max_h 2
        else if(max_h.size() < min_h.size())
        {
            max_h.push(min_h.top());
            min_h.pop();
        }
    }
    
    double findMedian() 
    {
        if(max_h.size() == min_h.size())
        {
            double mean = (min_h.top() + max_h.top())/2.0;
            return mean;
        }

        return max_h.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */