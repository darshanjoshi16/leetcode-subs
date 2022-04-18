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
    int kthSmallest(TreeNode* root, int k) 
    {
        //created the stack of the treenode elements
        stack<TreeNode*> St;
        
        //initialize the count and root node defination
        int count = 0;
        TreeNode *node = root;
       
        //if the stack is not empty or node is not empty
        while(not St.empty() || node)
        {
            //if the node  exists
            if(node)
            {
                //pushing the node into the stack and traversing the left area
                St.push(node);
                node = node->left;
            }else
            {
                //pop the node from the top of stack
                node = St.top(); St.pop();
                //if the count is increased then value is given to node
                if(++count==k) return node->val;
                node = node->right;
            }
        }
        return INT_MIN;
    }
};
