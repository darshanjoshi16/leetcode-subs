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
    #define Node TreeNode
    Node*prev;
    Node*first;
    Node*middle;
    Node*last;
    void solve(Node*root)
    {
        if(root==NULL)
            return;
        solve(root->left);
        if(root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new Node(INT_MIN); //keeps track of parent node
        solve(root);
        if(first&&last)
        {
            swap(first->val,last->val);
        }
        else
            swap(first->val,middle->val);
        return;
    }
};
