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
class Solution {
public:
    bool isMirror(TreeNode* rootLeft,TreeNode* rootRight){
        if(!rootLeft && !rootRight)
            return true;
        
        if(rootLeft==NULL && rootRight!=NULL)
            return false;
        
        if(rootLeft!=NULL && rootRight==NULL)
            return false;
        
        if(rootLeft->val!=rootRight->val)
            return false;
        
        
        return isMirror(rootLeft->right,rootRight->left) && isMirror(rootLeft->left,rootRight->right);
        
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};
