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
    int rob(TreeNode* root) {
        auto [countroot, uncountRoot] = DFS(root);
        return max(countroot,uncountRoot);
    }

    pair<int,int> DFS (TreeNode* root) {
        if (!root) return {0,0};
        pair<int,int> left,right;
        left = DFS(root->left);
        right = DFS(root->right);
        int uncount=0;
        if (left.first>0 &&right.first>0) uncount = left.first+right.first;
        else if(left.first>0)  uncount = left.first;
        else if(right.first>0)  uncount = right.first;
        int count = max(root->val+left.second +right.second,uncount);
        return {count,uncount};
    }
};