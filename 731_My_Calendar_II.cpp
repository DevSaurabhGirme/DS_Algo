// S.C = O(n)   T.C = O(1000*n)

class MyCalendarTwo {
public:
    // vector to store double booking overlapping regions
    vector<pair<int, int>> dovbReg;
    
    // to store all the possible bookings
    vector<pair<int, int>> allBook;    

    MyCalendarTwo() {}
    
    bool checkOverlap(int s1, int e1, int s2, int e2)
    {
        return max(s1, s2) < min(e1, e2);
    }

    pair<int, int> findOverlapRegions(int s1, int e1, int s2, int e2)
    {
        return {max(s1, s2) , min(e1, e2)};
    }

    bool book(int start, int end) 
    {
        // check for triplebooking
        for(pair<int, int> reg : dovbReg)
        {
            if(checkOverlap(reg.first, reg.second, start, end) == true)
            {
                // triple overlapping booking found
                return false;
            }
        }

        // check for double bookings
        for(pair<int, int> booking : allBook)
        {
            if(checkOverlap(booking.first, booking.second, start, end) == true)
            {
                dovbReg.push_back(findOverlapRegions(booking.first, booking.second, start, end));
            }
        }

        allBook.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */