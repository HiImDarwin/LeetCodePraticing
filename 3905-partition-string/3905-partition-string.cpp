class Solution {
  public:
    vector<string> partitionString(string s) {
      int n = s.length();
      vector<string> res;
      for(int i = 0; i < n; ++i) {
        TrieNode* root = &RootNode;
        string sol;
        while(i < n && root->children.count(s[i]) && root->children[s[i]]->isWord) {
          sol += s[i];
          root = root->children[s[i]];
          i++;
        }
        if(i != n) {
          sol += s[i];
          TrieNode *tmp = new TrieNode();
          tmp->isWord = true;
          root->children[s[i]] = tmp;
          res.push_back(sol);
        }
        
      }
      return res;
    }
  private:
    struct TrieNode {
      bool isWord;
      unordered_map<char,TrieNode*> children;
    };
    TrieNode RootNode;
};