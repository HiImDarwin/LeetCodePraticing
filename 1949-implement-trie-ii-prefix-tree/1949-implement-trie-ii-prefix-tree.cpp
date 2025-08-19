class Trie {
  struct node{
    node() {
      next.assign(26,nullptr);
    };
    //bool isEnd = false;
    vector<node*> next;
    int num = 0;
    int preFixCount = 0;
  };
  node* root;
public:
    Trie() {
      root = new node();
    }
    
    void insert(string word) {
      int n = word.length();

      node* curr = root;
      for (int i = 0; i < n; i++) {
        if (curr->next[word[i]-'a'] == nullptr) {
          node* newChar = new node();
          curr->next[word[i]-'a'] = newChar;
        }
        curr->preFixCount++;
        curr = curr->next[word[i]-'a'];
      }
      curr->num++;
      curr->preFixCount++;
    }
    
    int countWordsEqualTo(string word) {
      int n = word.length();
      node* curr = root;
      int i = 0;
      while (i < n && curr) {
        curr = curr->next[word[i]-'a'];
        i++;
      }
      if (i == n && curr) {
        return curr->num;
      }
      return 0;
    }
    
    int countWordsStartingWith(string prefix) {
      int n = prefix.length();
      node* curr = root;
      int i = 0;
      while (i < n && curr) {
        curr = curr->next[prefix[i]-'a'];
        i++;
      }
      if (i == n && curr) {
        return curr->preFixCount;
      }
      return 0;
    }
    
    void erase(string word) {
      int n = word.length();
      node* curr = root;
      int i = 0;
      while (i < n && curr) {
        curr = curr->next[word[i]-'a'];
        i++;
      }
      // check if word exist
      if (i != n || !curr || curr->num < 1) {
        return;
      }
      // delete word
      curr = root;
      i=0;
      while (i < n && curr) {
        node* ne =  curr->next[word[i]-'a'];
        curr->preFixCount--;
        // if (curr->preFixCount == 0) {
        //   curr->next[word[i]-'a'] = nullptr;
        //   if (curr != root) {
        //     delete curr;
        //   }
        // }
        curr = ne;
        i++;
      }
      curr->preFixCount--;
      curr->num--;
      // if (curr->num == 0 && curr->preFixCount == 0) {
      //   delete curr;
      // }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */