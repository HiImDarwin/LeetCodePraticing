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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key <root->val) {
            root->left = deleteNode(root->left,key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right,key);
        } else {
            if(!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if(!root->left) { // only right
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            } else if(!root->right) { // only left
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
    // deletion condition 1. no child->just delete 2. one level child-> child replace parents 3. more than one level child->find the successor
    TreeNode* findMin(TreeNode* node){
        while (node->left) node = node->left;
        return node;
    }
};