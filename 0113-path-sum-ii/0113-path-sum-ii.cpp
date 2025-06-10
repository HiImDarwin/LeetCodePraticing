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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> pathVal;
        vector<vector<int>> res;
        int currSum=0;
        DFS(root,targetSum,currSum,pathVal,res);
        return res;
        
    }
    void DFS (TreeNode* root, int targetSum, int &currSum,vector<int> &pathVal,vector<vector<int>> &res ) {
        currSum+=root->val;
        pathVal.push_back(root->val);
        if(!root->left && !root->right && currSum == targetSum) {
            res.push_back(pathVal);
        }
        
        if(root->left) DFS(root->left,targetSum,currSum,pathVal,res);
        if(root->right) DFS(root->right,targetSum,currSum,pathVal,res);
        pathVal.pop_back();
        currSum-=root->val;
    }
};