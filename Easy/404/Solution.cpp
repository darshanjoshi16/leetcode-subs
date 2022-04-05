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
    int sumOfLeftLeaves(TreeNode* root) {
        
        //if the root is null then it will return the value of summation is 0
        if(root==NULL)
             return 0;
    
        //it will check it the left node existance
        if(root->left && root->left->left==NULL && root->left->right==NULL)
        {
            return root->left->val+sumOfLeftLeaves(root->right);
        }
    
        //recursive returnning answer
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
     }
};
