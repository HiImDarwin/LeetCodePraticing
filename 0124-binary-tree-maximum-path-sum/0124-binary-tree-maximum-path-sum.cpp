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
    
    int maxPathSum(TreeNode* root) {
        int maximum=INT_MIN;
        DFS(root,maximum);
        return maximum ==INT_MIN ? 0 :maximum;
    }
    // postorder traversal 並且記錄left child與right child到此點的值
    int DFS(TreeNode* root, int &maximum) {
        if(!root) return 0;
        int left=0,right=0;
        left = DFS(root->left,maximum);
        right = DFS(root->right,maximum);
        int x =root->val;
        if(left>0 && right>0) {
            x += left+right;
        } else if(left>0 ) {
            x += left;
        } else if(right>0) {
            x+= right;
        }
        maximum = max(maximum,x);
        if(left>0 && right>0) {
            if(left>right) return root->val+left;
            else return  root->val+right;
        } else if(left>0 ) {
            return root->val+left;
        } else if(right>0) {
            return root->val+right;
        }
        return  root->val;
    }
};