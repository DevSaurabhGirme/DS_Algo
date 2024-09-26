// T.C = O(log n)   S.C = O(n)

class MyCalendar {
public:
    set<pair<int, int>> oset;
    MyCalendar() 
    {}
    
    bool book(int start, int end) 
    {
        // Find the first event that starts after 
        // or at same time of {start, end}

        // return an iterator pointing to integer just >= start
        auto it = oset.lower_bound({start, end});

        // Check if the current event overlaps with the next event
        if(it != oset.end() && it -> first < end) 
        {
            return false;
        }

        // Check if the current event overlaps with the previous event
        // also iterator shouldn't point to the first element of set
        if(it != oset.begin()) 
        {
            auto prevIt = prev(it);
            
            if(start < prevIt -> second) 
            {
                return false;
            }
        }

        oset.insert({start, end});
        
        return true;
    }
};