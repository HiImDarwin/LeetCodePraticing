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
    TreeNode* str2tree(string s) {
      if(s.length() == 0) return  nullptr;
      int index = 0;
      return buildTree(s,index);
    }

    TreeNode* buildTree(string s , int &index) {
      int num = 0;
      int sign = 1;
      if(s[index] == '-') {
        sign = -1;
        index++;
      }
      while(index < s.length() && isdigit(s[index])) {
        num = num * 10 + (s[index] - '0');
        index++;
      }

      TreeNode* node = new TreeNode(num*sign);

      // while(index < s.length() && s[index] == '(') {
      //   index++;
      //   if(!node->left) {
      //     node->left = buildTree(s,index);
      //   } else {
      //     node->right = buildTree(s,index);
      //   }
      // }
      if(index < s.length() && s[index] == '(') {
        index++;
        node->left = buildTree(s,index);
      }

      if(index < s.length() && s[index] == '(') {
        index++;
        node->right = buildTree(s,index);
      }


      if(s[index] == ')'){
        index++;
      }
      return node;
    }
};


/*
so

question
1. is there always two child? if only one can i construct left node?
2. the input is like
  4(1(2)(3))(3)
3. i suggest the paenthesis will always be valid pair ()
*/