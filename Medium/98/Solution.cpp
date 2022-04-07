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
bool check(long min,long max,TreeNode *root){

    if(root==NULL){
        return true;
    }
    if(root->val <=min || root->val >=max){
        return false;
    }

    bool temp1= check(min,root->val,root->left);   
    bool temp2= check(root->val,max,root->right);

    
    return temp1&&temp2;
}
bool isValidBST(TreeNode* root) {
   
    return check(LONG_MIN,LONG_MAX,root);
    
}
};
