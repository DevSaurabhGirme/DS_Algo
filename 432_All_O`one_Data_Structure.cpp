// T.C = O(1)   S.C = O(n)

class AllOne {
public:
    struct Node
    {
        int count;
        // list at each node to store string values
        list<string> keys;
        Node* next;
        Node* prev;

        Node(int cnt)
        {
            count = cnt;
            next = NULL;
            prev = NULL;
        }
    };

    // to store string and its address in the list
    unordered_map<string, Node*> unmap;

    Node* head;
    // to retrieve maximum count string
    Node* last;

    void addNode(Node* prevNode, int count)
    {
        Node* newNode = new Node(count);
        newNode -> next = prevNode -> next;
        newNode -> prev = prevNode;

        // if this newNode is not last in the list
        if(newNode -> next != NULL)
        {
            newNode -> next -> prev = newNode;
        }

        prevNode -> next = newNode;

        // updating the last node
        if(prevNode == last)
        {
            last = newNode;
        }
    }

    void removeNode(Node* node)
    {
        node -> prev -> next =node -> next;
        
        // if node to be deleted is not the last node
        if(node -> next != NULL)
        {
            node -> next -> prev = node -> prev;
        }

        // if node to be deleted is the last node itself
        if(last == node)
        {
            last = node -> prev;
        }

        delete node;
    }

    AllOne() 
    {
        // initializing the list
        head = new Node(0);
        last = head;
    }
    
    void inc(string key) 
    {
        if(unmap.find(key) == unmap.end())
        {
            // key(string) doesn't exist
            // so first check il the list if head is the only node in the list
            // or node with count 1 doesn't exist 
            // hence create one
            if(head -> next == NULL || head -> next -> count != 1)
            {
                // head -> next = newNode performed in below function
                addNode(head, 1);
            }

            head -> next -> keys.push_front(key);
            unmap[key] = head -> next; 
        }
        else
        {
            // key(string) already exists
            // hence increase its count and move a node forward
            // currNode is the pointer storing address to
            // key(string) from the map
            Node* currNode = unmap[key];
            int currCount = currNode -> count;

            // if node with current count doesn't exist
            if(currNode -> next == NULL || currNode -> next -> count != currCount+1)
            {
                // create
                addNode(currNode, currCount+1);
            }

            // insert the key(string) in the current node
            currNode -> next -> keys.push_front(key);
            // updating the address
            unmap[key] = currNode -> next;
            // delete the string from current node which is 
            // recently moved to anothernode
            currNode -> keys.remove(key);
            
            // like we deleted the string above
            // we now delete the node itself if empty
            if(currNode -> keys.empty())
            {
                removeNode(currNode);
            }
        }
    }
    
    void dec(string key) 
    {
        Node* currNode = unmap[key];
        int currCount = currNode -> count;
        
        // count tobe made 0 hence delete
        if(currCount == 1)
        {
            unmap.erase(key);
        }
        else
        {
            // node with required count not avaliable
            if(currNode -> prev -> count != currCount-1)
            {
                // hence create
                addNode(currNode -> prev, currCount-1);
            }

            // string reflected in the new node's keys
            currNode -> prev -> keys.push_front(key);
            // update the address in the map
            unmap[key] = currNode -> prev;
        }

        currNode -> keys.remove(key);
        // if no strings present in current node
        if(currNode -> keys.empty())
        {
            removeNode(currNode);
        }
    }
    
    string getMaxKey() 
    {   
        // no node present
        if(last == head)
        {
            return "";
        }

        return last -> keys.front();
    }
    
    string getMinKey() 
    {
        if(head -> next == NULL)
        {
            return "";
        }

        return head -> next -> keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */