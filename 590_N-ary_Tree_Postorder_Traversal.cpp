/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// T.C = O(n)    S.C = O(1) + n(stack)

class Solution {
public:
    void post_DFS(Node* child_node, vector<int>& nodes)
    {
        // reached the leaf node
        if(child_node == NULL)
        {
            return;
        }

        // iterate over children of child_node
        for(auto& node : child_node -> children)
        {
            post_DFS(node, nodes);
        }

        nodes.push_back(child_node -> val);
    }

    vector<int> postorder(Node* root) 
    {
        vector<int> nodes;

        post_DFS(root, nodes);

        return nodes;    
    }
};