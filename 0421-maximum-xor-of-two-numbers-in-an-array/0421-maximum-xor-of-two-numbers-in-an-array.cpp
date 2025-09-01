class Solution {
  class TrieNdoe {
    public:
      TrieNdoe* next[2];
  };
public:
    // int findMaximumXOR(vector<int>& nums) {
    //   TrieNdoe* root = new TrieNdoe();
    //   for (int& num : nums) {
    //     TrieNdoe* curr = root;
    //     for(int i = 31; i >= 0; --i) {
    //       if (curr->next[((num>>i) & 1)] == nullptr) {
    //         TrieNdoe* newNode = new TrieNdoe();
    //         curr->next[((num>>i) & 1)] = newNode;
    //       }
    //       curr = curr->next[((num>>i) & 1)];
    //     }
    //   }

    //   int res = 0;
    //   for (auto& num : nums) {
    //     TrieNdoe* curr = root;
    //     int XORResult = 0;
    //     for (int i = 31; i>=0; --i) {
    //       if (curr->next[((num>>i )& 1)^1] != nullptr) {
    //         curr = curr->next[((num>>i )& 1)^1];
    //         XORResult ^= (1 << i);
    //       } else {
    //         curr = curr->next[(num>>i )& 1];
    //       }
    //     }
    //     res = max(res,XORResult);
    //   }
    //   return res;
    // }

    int findMaximumXOR(vector<int>& nums) {
      TrieNdoe* root = new TrieNdoe();

      for (const auto& num : nums) {
        TrieNdoe* node = root;
        for (int i = 31; i >= 0; --i) {
          if (node->next[(num >> i) & 1] == nullptr) {
            node->next[(num >> i) & 1] = new TrieNdoe();
          }
          node = node->next[(num >> i) & 1];
        }
      }
      int res = 0;
      for (const auto& num : nums) {
        TrieNdoe* curr = root;
        int XORResult = 0;
        for (int i = 31; i >= 0; --i) {
          if (curr->next[((num >> i) & 1) ^ 1] != nullptr) {
            curr = curr->next[((num >> i) & 1) ^ 1];
            XORResult ^= (1 << i);
          } else {
             curr = curr->next[((num >> i) & 1)];
          }
        }
        res = max(res, XORResult);
      }
    
      return res;
    }
};


/*
[3,10,5,25,2,8]

 000011
 001010
 000101
 011001
 000010
 001000
 */