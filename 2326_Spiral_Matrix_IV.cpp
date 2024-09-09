/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// T.C = O(m*n)     S.C = O(n)

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        // result matrix initialized with -1
        vector<vector<int>> spiral (m, vector<int> (n,-1));    
    
        // denoting direction to travel in
        // 0->east, 1->south, 2->west, 3->north
        // l -> r , t -> b  , r -> l , b -> t
        int dir = 0;

        // upper boundary
        int topRow = 0;
        
        // lower boundary
        int btmRow = m-1;
        
        // leftmost boundary
        int leftCol = 0;
        
        // rightmost boundary
        int rghtCol = n-1;
    
        // while(topRow <= btmRow && leftCol <= rghtCol)
        while(head != NULL)
        {
            // l -> r(east)
            if(dir == 0)
            {
                // row traversal
                for(int i = leftCol; head != NULL && i <= rghtCol; i++)
                {
                    spiral[topRow][i] = head -> val;
                    head = head -> next;
                }
                // moving a row down
                topRow++;
            }
        
            // t -> b(south)
            if(dir == 1)
            {
                // column traversal
                for(int i = topRow; head != NULL && i <= btmRow; i++)
                {
                    spiral[i][rghtCol] = head -> val;
                    head = head -> next;
                }
                // moving a column left
                rghtCol--;;
            }

            // r -> l(west)
            if(dir == 2)
            {
                // row traversal
                for(int i = rghtCol; head != NULL && i >= leftCol; i--)
                {
                    spiral[btmRow][i] = head -> val;
                    head = head -> next;
                }
                // moving a row up
                btmRow--;
            }

            // b -> t(north)
            if(dir == 3)
            {
                // column traversal
                for(int i = btmRow; head != NULL && i >= topRow; i--)
                {
                    spiral[i][leftCol] = head -> val;
                    head = head -> next;
                }
                // moving a column right
                leftCol++;
            }

            dir = (dir+1) % 4;
        }

        return spiral;

    }
};