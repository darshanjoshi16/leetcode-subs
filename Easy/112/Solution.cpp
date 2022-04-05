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
    int solve(TreeNode* root,int& temp,int& chk,int t)
    {
        if(!root)
        {return 0;}
temp+=root->val;
if(temp==t && !root->left && !root->right){
chk=1;
}
int l=solve(root->left,temp,chk,t);
int r=solve(root->right,temp,chk,t);
temp-=root->val;
return temp;
}
bool hasPathSum(TreeNode* root, int targetSum) {
int temp=0;
int chk=0;
solve(root,temp,chk,targetSum);
return chk;
}
};
