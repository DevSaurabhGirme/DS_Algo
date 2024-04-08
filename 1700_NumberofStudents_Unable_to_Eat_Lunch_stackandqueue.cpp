class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int n = students.size();

        stack<int> sandstk;
        queue<int> studqueue;

        for(int i = 0; i < n; i++)
        {
            // since it is a stack we fill from last element which goes to the bottom
            sandstk.push(sandwiches[n-1-i]);

            studqueue.push(students[i]);
        }

        // number of conse3ctive students remain unserved 
        int unserved = 0;

        // most of the tmies we break the loop due to 2nd condition
        while(!studqueue.empty() && unserved < studqueue.size())
        {
            if(sandstk.top() == studqueue.front())
            {
                sandstk.pop();
                studqueue.pop();

                unserved = 0;
            }
            else
            {
                // student in ther front is placed last in the queue as his prefered sandwich is not found
                studqueue.push(studqueue.front());
                studqueue.pop();

                unserved++;
            }
        }
        return unserved; // studqueue.size()
    }
};