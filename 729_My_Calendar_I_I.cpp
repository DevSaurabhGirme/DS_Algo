// T.C = O(n^2)     S.C = O(n)

class MyCalendar {
public:
    vector<pair<int,int>> vec;

    MyCalendar() 
    {}
    
    bool book(int start, int end) 
    {
        for(int i = 0;i < vec.size(); i++)
        {
            // here we find that it is overlap or not using this condotion 
            // a < e and s < b
            if(vec[i].first < end && start < vec[i].second)
            {
                return false;
            }
        }

        vec.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */