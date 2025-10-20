class Solution {
  
  public:

    int findMaximumXOR(vector<int>& nums) {
      root_ = new TrieNode();
      int res = 0;

      for (auto& num : nums) {
        addNum(num);
        int val = findMax(num);
        res = max(res, num ^ val);
      }

      return res;
    }

  private:

    void addNum(int num) {
      TrieNode* node = root_;
      for (int offset = 30; offset >= 0; offset--) {
        int bit = (num >> offset) & 1;
        if (node->next[bit] == nullptr) {
          node->next[bit] = new TrieNode();
        }
        node = node->next[bit];
      }
      node->val = num;
    }

    int findMax(int num) {
      TrieNode* node = root_;
      for (int offset = 30; offset >= 0; offset--) {
        int bit = ((num >> offset) & 1) ^ 1;
        if (node->next[bit] == nullptr) {
          bit ^= 1;
        }
        node = node->next[bit];
      }
      return node->val;
    }

    struct TrieNode {
      vector<TrieNode*> next;
      int val;

      TrieNode() : next(2, nullptr), val(0) {};
    };
    TrieNode* root_;
};

/*
  xor

*/