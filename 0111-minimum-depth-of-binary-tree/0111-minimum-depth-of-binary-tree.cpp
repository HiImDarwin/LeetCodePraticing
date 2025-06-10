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
    // int minDepth(TreeNode* root) {
    //     if(!root) return 0;
    //     return DPS(root, 0);
    // }

    // int DPS(TreeNode* root, int deepth) {
    //     deepth++;
    //     int left = INT_MAX;
    //     int right = INT_MAX;
    //     if(!root->left && !root->right) return deepth;
    //     if(root->left) left = DPS(root->left,deepth);
    //     if(root->right) right = DPS(root->right, deepth);
    //     return min(left,right);
    // }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left)+1,minDepth(root->right)+1);
    }
};