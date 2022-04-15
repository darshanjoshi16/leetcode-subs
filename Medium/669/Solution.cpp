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
    // to store the leftmost node of right child
    TreeNode *temp;
    
    // to get leftmost node of right child
    TreeNode* left_node(TreeNode* root){
        if(root->left==nullptr) return root;
        return left_node(root->left);
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;
        
        // to check if node is to be deleted
        if(root->val<low or root->val>high){
            
            // trim it's left and right children
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            
            // if node doesn't have right child then return it's left
            if(root->right == nullptr) return root->left;
            
            // add the left node to leftmost of the right child 
            temp = left_node(root->right);
            temp->left = root->left;
            return root->right;
        }
        
        // root doesn't need to be deleted so trim it's children
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
