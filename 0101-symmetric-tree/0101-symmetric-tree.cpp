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
    // bool isSymmetric(TreeNode* root) {
    //     if(!root) return true;
    //     unordered_map<int,int> left,right;
    //     leftChild(root->left,left,1);
    //     rightChild(root->right,right,1);
    //     return left == right;
    // }

    // void leftChild(TreeNode* root, unordered_map<int,int> &mp,int num) {
    //     if(!root) return;
    //     mp[num] = root->val;
    //     leftChild(root->left,mp,num*2);
    //     leftChild(root->right,mp,num*2+1);
    // }
    // void rightChild(TreeNode* root,unordered_map<int,int> &mp,int num){
    //     if(!root) return;
    //     mp[num] = root->val;
    //     rightChild(root->left,mp,num*2+1);
    //     rightChild(root->right,mp,num*2);
    // }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
private:
    bool isMirror(TreeNode* t1, TreeNode*t2) {
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        return (t1->val == t2->val) && isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
    }
};