/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : v\al(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder,int ileft,int iright,int pleft,int pright) {
        if(ileft >iright || pleft>pright) return nullptr;
        if(ileft -iright ==0) return new TreeNode(inorder[ileft]);
        int rootVal = postorder[pright];
        int idx = ileft;
        while(inorder[idx]!=rootVal && idx<=iright) idx++;
        TreeNode* root = new TreeNode(rootVal);
        int left_length = idx-ileft;
        root->left = buildTree(inorder,postorder,ileft,idx-1,pleft,pleft+left_length-1);
        root->right = buildTree(inorder,postorder,idx+1,iright,pleft+left_length,pright-1);
        return root;
    }
};