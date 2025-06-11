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
    //postorder traversal
    // every root return how many coin thry need or they have
    // every root count the move need between he and his child
    // gather the coin to the root place if the coin more than node account
    int distributeCoins(TreeNode* root) {
        if(!root) return 0;
        int moveCount=0;
        coinDFS(root, moveCount);
        return moveCount;
    }

    int coinDFS(TreeNode* root,int & moveCount) { // return the coin  numer
        if(!root) return 0;

        int leftCoin = coinDFS(root->left, moveCount);
        int rightCoin = coinDFS(root->right, moveCount);

        moveCount+= abs(leftCoin) + abs(rightCoin);

        return root->val+leftCoin+rightCoin-1;
    }
};