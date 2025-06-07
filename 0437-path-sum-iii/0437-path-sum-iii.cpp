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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int,int> pathVal;
        pathVal[0] = 1;
        long long int sum=0;
        return DFS(root,targetSum,pathVal,sum);
        
    }

    int DFS(TreeNode* root, int targetSum,unordered_map<long long int,int> &pathVal, long long int &sum){
        if(!root) return 0;
        int res=0;
        sum += root->val;
        if(pathVal.count(sum-targetSum)) {
            res += pathVal[sum-targetSum];
        }
        pathVal[sum]++;
        res += DFS(root->left,targetSum,pathVal,sum);
        res += DFS(root->right,targetSum,pathVal,sum);
        if(--pathVal[sum] == 0) pathVal.erase(sum);
        sum -= root->val;
        return res;
    }
};