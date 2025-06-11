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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = build(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
        return root;
    }

    TreeNode* build(vector<int>& preorder,int preL, int preR, vector<int>& postorder,int posL, int posR) {
       if(preL>preR) return nullptr;
       TreeNode *root = new TreeNode(preorder[preL]);
       if(preL==preR) return root;
       if(preorder[preL+1] == postorder[posR-1] )  { // only one child
            root -> left = build(preorder,preL+1,preR,postorder,posL,posR-1);
       } else {
            int x= preorder[preL+1];
            int i = posL;
            while(postorder[i]!= x){
                i++;
            }
            int leftSize = i-posL+1;
            root->left = build(preorder,preL+1,preL+leftSize,postorder,posL,posL+leftSize-1);
            root->right = build(preorder,preL+leftSize+1,preR,postorder,posL+leftSize,posR-1);
       }
       return root;
    }
};

