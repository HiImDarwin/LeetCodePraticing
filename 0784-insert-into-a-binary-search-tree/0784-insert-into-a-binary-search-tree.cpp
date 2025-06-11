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
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if(!root) return new TreeNode(val);
    //     insertion(root, val);
    //     return root;
    // }
    // void insertion(TreeNode* root, int val) {
    //     if(root->val >=val) {
    //         if(!root->left) root->left = new TreeNode(val);
    //         else insertion(root->left,val);
    //     } else if(root->val <val ){
    //         if (!root->right) root->right = new TreeNode(val);
    //         else insertion(root->right,val);
    //     }
    // }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* tmp = root;
        while(true) {
            if(tmp->val > val){
                if(!tmp->left) {
                    tmp->left = new TreeNode(val);
                    break;
                }
                tmp = tmp->left;
            } else {
                 if(!tmp->right) {
                    tmp->right = new TreeNode(val);
                    break;
                }
                tmp = tmp->right;
            }
        }
        return root;
    }
};