class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>min_h;

    int K = 0;

    KthLargest(int k, vector<int>& nums) 
    {
        K = k;
        for(int &num : nums)
        {
            min_h.push(num);

            if(min_h.size() > k)
            {
                min_h.pop();
            }
        }
    }
    
    int add(int val) 
    {
        min_h.push(val);

        if(min_h.size() > K)
        {
            min_h.pop();
        }    

        return min_h.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */