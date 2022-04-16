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
private:
    /*
    return: Sum of left node's total
    */
    int helper(TreeNode* root, int parentNewVal) {
        
        // Return parent's value when NULL
        if(!root) {return parentNewVal;}
        
        // In a BST, we know our "right" child will have a value "greater" than us. So, we know, whatver, we receive from our right child, we can add to our own value to get the greater value.        
        int rightSum = helper(root->right, parentNewVal);         
        root->val += rightSum;
        
        // In a BST, we know our "left" child will have a value "smaller" than us. Therefore, we need to tell our value to the left child, so it can use it wisely. Now a wise thing for my left child will be to pass it on to its right child because the right child of my left will still be smaller than me. 
        int leftSum = helper(root->left, root->val);
        
        // The reason, we return our left child's value because, we might be the right child of our parent and our left's child value will be greater than our parent.
        return leftSum;
    }

    
public:
    TreeNode* convertBST(TreeNode* root) {        
        int answer = helper(root, 0);        
        return root;        
    }
};
