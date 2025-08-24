class CombinationIterator {
    string charStr;
    vector<int> pos;
    int N;
    int M;
    bool end = false;
public:
    CombinationIterator(string characters, int combinationLength) {
      charStr = characters;
      N = characters.length();
      M = combinationLength;
      pos.resize(M,0);
      for (int i = 0; i < M; i++) {
        pos[i] = i;
      }
    }
    
    string next() {
      string s;
      for (int i = 0; i < M; i++) {
        s += charStr[pos[i]];
      }
      if (!update()) {
        end = true;
      }
      return s;
    }
    
    bool hasNext() {
      return !end;
    }
private:
  bool update() {
    int i = M-1;
    while (i >= 0 && pos[i] == N - (M - i)) {
      i--;
    }
    if (i < 0) return false;
    pos[i]++;
    for (int j = i + 1; j < M; j++) {
      pos[j] = pos[j-1] + 1;
    }
    return true;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();



 12345
 X X X 
 */