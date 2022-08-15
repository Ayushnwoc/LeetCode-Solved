/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        Node* ans = new Node(node->val);
        if(node->neighbors.size() == 0)
        {
            return ans;
        }
        if(m.find(node) != m.end())
        {
            return ans;
        }
        m[node] = ans;
        for(auto i : node->neighbors)
        {
            if(m.find(i) != m.end())
            {
                ans->neighbors.push_back(m[i]);
            }
            else
            {
                ans->neighbors.push_back(cloneGraph(i));
            }
        }
        return ans;
    }
    unordered_map<Node* , Node*>m;
};