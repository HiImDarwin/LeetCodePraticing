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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        unordered_map<int,int> left,right;
        leftChild(root->left,left,1);
        rightChild(root->right,right,1);
        return left == right;
    }

    void leftChild(TreeNode* root, unordered_map<int,int> &mp,int num) {
        if(!root) return;
        mp[num] = root->val;
        leftChild(root->left,mp,num*2);
        leftChild(root->right,mp,num*2+1);
    }
    void rightChild(TreeNode* root,unordered_map<int,int> &mp,int num){
        if(!root) return;
        mp[num] = root->val;
        rightChild(root->left,mp,num*2+1);
        rightChild(root->right,mp,num*2);
    }
};