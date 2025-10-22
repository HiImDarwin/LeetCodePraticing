class Solution {
  struct TrieNode {
    bool isWord;
    vector<TrieNode*> next;
    TrieNode(): isWord(false), next(26,nullptr) {};
  };
  int m,n;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      TrieNode* root = new TrieNode();
      
      for (const auto& word : words) {
        TrieNode* node = root;
        for (const auto& c : word) {
          if (!node->next[c - 'a']) {
            node->next[c - 'a'] = new TrieNode();
          }
          node = node->next[c - 'a'];
        }
        node->isWord = true;
      }

      m = board.size();
      n = board[0].size();
      vector<string> res;
      string validWord = "";
      vector<vector<bool>> visited(m,vector<bool>(n,false));
      for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j++) { 
          TrieNode* node = root->next[board[i][j] - 'a'];
          if (node) {
            dfs(board, node, visited, validWord, res, i, j);
          }
        }
      }

      return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, vector<vector<bool>>& visited,
            string &validWord, vector<string>& res, int x, int y) {
      visited[x][y] = true;
      // add char
      validWord.push_back(board[x][y]);
      // add word
      if (checkWord(node)) {
        res.push_back(validWord);
      }
      for (auto [dx, dy] : directions) {
        int nei_x = x + dx;
        int nei_y = y + dy;
        if (nei_x < 0 || nei_x >= m || nei_y < 0 || nei_y >= n || visited[nei_x][nei_y]) {
          continue;
        }
        TrieNode* nextNode = checkChar(node, board[nei_x][nei_y]);
        if (nextNode) {
          dfs(board, nextNode, visited, validWord, res, nei_x, nei_y);
        }
        
      }
      // pop char
      visited[x][y] = false;
      validWord.pop_back();
    }

    TrieNode* checkChar(TrieNode* node, char c) {
      return node->next[c - 'a'];
    }

    bool checkWord(TrieNode* node) {
      if (node->isWord) {
        node->isWord = false;
        return true;
      }
      return false;
    }

    const vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

/*
trie + dfs


*/