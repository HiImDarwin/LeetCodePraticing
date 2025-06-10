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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        if(!root) return false;
        return DFS(root,targetSum,sum);
        
    }
    bool DFS(TreeNode* root, int targetSum, int &currSum){
        bool result=false;
        currSum += root->val;
        if(!root->left&& !root->right) {
            if(currSum == targetSum) return true;
            currSum-= root->val;
            return result;
        }
        if(root->left) result |= DFS(root->left,targetSum,currSum);
        if(root->right) result |= DFS(root->right,targetSum,currSum);
        currSum-= root->val;
        return result;
    }
};