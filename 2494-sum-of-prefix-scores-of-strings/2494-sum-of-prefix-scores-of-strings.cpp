class Solution {

  struct node {
    node() {
      for (int i = 0; i < 26; i++) next[i] = nullptr;
      prefix = 0;
    }
    node* next[26];
    int prefix = 0;
  };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
      node* root = new node();
      
      for (string& s : words) {
        node* curr = root;
        for (char& c: s){
          if(curr->next[c-'a'] == nullptr) {
            node* newChar = new node();
            curr->next[c-'a'] = newChar;
          }
          curr->prefix++;
          curr = curr->next[c-'a'];
        }
        curr->prefix++;
      }

      vector<int> res;
      for (string& s : words) { 
        node* curr = root;
        int count = 0;
        for (char& c: s){
          curr = curr->next[c-'a'];
          count += curr->prefix;
        }
        res.push_back(count);
      }

      return res;
    }
};

/*

*/