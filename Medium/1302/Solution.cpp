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
    int deepestlvl, deepestsum;
    void dfs(TreeNode* s, int level){
        if(s == nullptr) return;
        if(level == deepestlvl){
            deepestsum += s->val;
        } else if(level > deepestlvl){
            deepestlvl = level;
            deepestsum = s->val;
        }
        dfs(s->left, level+1);
        dfs(s->right, level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        deepestlvl = 0, deepestsum = 0;
        dfs(root, 0);
        return deepestsum;
    }
};
