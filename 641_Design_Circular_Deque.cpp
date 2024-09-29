class MyCircularDeque {
public:

    vector<int> dq;
    int x;
    int f;
    int r;
    int currCount;

    MyCircularDeque(int k) 
    {
        x = k;
        dq = vector<int>(x, 0);

        f = 0;    
        r = x-1;
        currCount = 0;
    }
    
    bool insertFront(int value) 
    {
        if(isFull() == true)
            return false;

        f = (f - 1 + x) % x;
        dq[f] = value;

        currCount++;
        return true;    
    }
    
    bool insertLast(int value) 
    {
        if(isFull() == true)
            return false;

        r = (r + 1) % x;
        dq[r] = value;

        currCount++;
        return true;    
    }
    
    bool deleteFront() 
    {
        if(isEmpty() == true)
            return false;

        f = (f + 1) % x;
        
        currCount--;
        return true;    
    }
    
    bool deleteLast() 
    {
        if(isEmpty() == true)
            return false;

        r = (r - 1 + x) % x;
        
        currCount--;
        return true;    
    }
    
    int getFront() 
    {
        if(isEmpty() == true)
            return -1;    

        return dq[f];    
    }
    
    int getRear() 
    {
        if(isEmpty() == true)
            return -1;    

        return dq[r];
    }
    
    bool isEmpty() 
    {
        return currCount == 0;    
    }
    
    bool isFull() 
    {
        return currCount == x;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */