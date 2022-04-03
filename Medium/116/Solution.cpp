/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connect(Node *root, Node *parent, bool left) {
        if (root == nullptr) return;
        if (left) {
            root->next = parent->right;
        }
        else {
            if (parent->next) root->next = parent->next->left;
            else root->next = nullptr;
        }
        connect(root->left, root, true);
        connect(root->right, root, false);
    }

    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        root->next = nullptr;
        connect(root->left, root, true);
        connect(root->right, root, false);
        return root;
    }
};
