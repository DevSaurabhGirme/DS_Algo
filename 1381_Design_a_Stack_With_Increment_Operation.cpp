class CustomStack {
public:
    // vector respresenting stack to store elements
    vector<int> arr_stk;
    // to store incrementsfor required elements
    vector<int> inc;

    int n;

    CustomStack(int maxSize) 
    {
        n = maxSize;    
    }
    
    void push(int x) 
    {
        if(arr_stk.size() < n)
        {
            arr_stk.push_back(x);
            inc.push_back(0);
        }    
    }
    
    int pop() 
    {
        if(arr_stk.size() == 0)
        {
            return -1;
        }    
        
        // index of top element as if were in a stack
        int idx = arr_stk.size() - 1;
    
        if(idx > 0)
        {
            // lazy propogation
            inc[idx-1] += inc[idx];
        }

        // incremented the element's value and ready to pop
        int top_val = arr_stk[idx] + inc[idx];
        arr_stk.pop_back();
        // erase the increment value
        inc.pop_back();

        return top_val;
    }
    
    void increment(int k, int val) 
    {
        int Idx = min(k, (int)arr_stk.size()) -1;
        // update the inc vector array
        if(Idx >= 0)
        {
            inc[Idx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */