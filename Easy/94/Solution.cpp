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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>ans;
    stack<TreeNode*>s;
    TreeNode* node=root;
    while(1)
    {
        if(node!=NULL)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            if(s.empty())
                break;
            else
            {
                ans.push_back(s.top()->val);
                node=s.top()->right;
                s.pop();
            }
        }
    }
    return ans;
    }
};
