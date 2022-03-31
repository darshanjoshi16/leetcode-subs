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

class Solution {
public:
    
    //solve method which takes the root node and answer vector as input parameters
    void solve(Node* root,vector<int> &ans)
    {
        //if its not root node return to main function
        if(!root) return;
        //push the value of node into answer vector
        ans.push_back(root->val);
        //recursively applied the function for all the nodes
        for(auto node : root->children){
            solve(node,ans);
        }
    }
    
    //created the vector of preorder resultant vector
    vector<int> preorder(Node* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};
