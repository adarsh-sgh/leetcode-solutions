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
    unordered_map<int, Node*>mp;    
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(mp.count(node->val))return mp[node->val];
         mp[node->val] = new Node(node->val);
        Node *nn = mp[node->val];
        for(auto &nbr: node->neighbors){
            nn->neighbors.push_back(cloneGraph(nbr));
        } 
        return nn;
    }
};