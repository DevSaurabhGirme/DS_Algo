// T.C = O(6!)      S.C = O(6!)

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string start = "";

        // converting the intial state to string
        for(int i = 0; i < 2; i++) 
        {
            for(int j = 0; j < 3; j++) 
            {
                start += to_string(board[i][j]);
            }
        }

        // solved state
        string target = "123450";

        // queue to store state
        queue<string> que;
        que.push(start);
        
        // map to store index of zero and its possible swapping indices
        unordered_map<int, vector<int>> unmap;
        unmap[0] = {1, 3};
        unmap[1] = {0, 2, 4};
        unmap[2] = {1, 5};
        unmap[3] = {0, 4};
        unmap[4] = {1, 3, 5};
        unmap[5] = {2, 4};

        // set to store formed sets to avoid redunduncy
        unordered_set<string> visited;
        visited.insert(start);

        // moves
        int level = 0;
        while(!que.empty()) 
        {
            int n = que.size();

            // Processing all elements at current level
            while(n--) 
            {
                string currState = que.front();
                que.pop();

                // final state found
                if(currState == target) 
                {
                    return level;
                }

                // finding index of 0
                int indexOfZero = currState.find('0');
                
                // then retriving index from map
                for(int swapIdx : unmap[indexOfZero]) 
                {
                    string newState = currState;
                    // and perform one move a time
                    swap(newState[indexOfZero], newState[swapIdx]);
                    
                    // if not visited already
                    if(visited.find(newState) == visited.end()) 
                    {
                        que.push(newState);
                        visited.insert(newState);
                    }
                }
            }

            level++;
        }

        return -1;

    }
};