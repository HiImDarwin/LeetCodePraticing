class Trie {
    
public:
    Trie() {
      root_ = new TrieNode();
    }
    
    void insert(string word) {
      TrieNode* node = root_;
      for (char& c : word) {
        if (node->children.find(c) == node->children.end()) {
          node->children[c] = new TrieNode();
          
        }
        node = node->children[c];
      }
      node->isWord = true;
    }
    
    bool search(string word) {
      TrieNode* node = root_;
      for (char& c : word) {
        if (node->children.find(c) == node->children.end()) {
          return false;
        }
        node = node->children[c];
      }
      return node->isWord;
    }
    
    bool startsWith(string prefix) {
      TrieNode* node = root_;
      for (char& c : prefix) {
        if (node->children.find(c) == node->children.end()) {
          return false;
        }
        node = node->children[c];
      }
      return true;
    }
  private:
    struct TrieNode {
      bool isWord = false;
      unordered_map<char, TrieNode*> children;
    };
    TrieNode* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */