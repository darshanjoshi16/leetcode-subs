/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    TreeNode* root;
    stack<TreeNode*> st;
    int temp;
public:
    BSTIterator(TreeNode* BSTroot) {
        root=BSTroot;
        while(root) {
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        temp=st.top()->val;
        root=st.top()->right;
        st.pop();
        while(root){
            st.push(root);
            root=root->left;
        }
        return temp;
    }
    
    bool hasNext() {
        if(st.size()) return 1;
        return 0;
    }
};
//Average Time Complexity for each operation : O( 1 )
//Space Complexity : O( h ), h is total height of nodes

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
