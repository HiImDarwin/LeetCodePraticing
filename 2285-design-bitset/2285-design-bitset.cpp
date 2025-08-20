class Bitset {
  vector<int> bitVec;
  vector<int> inverseVec;
  int OneCount;
  int n;
public:
    Bitset(int size) {
      bitVec.assign(size,0);
      inverseVec.assign(size,1);
      OneCount = 0;
      n = size;
    }
    
    void fix(int idx) {
      if (bitVec[idx] == 0) {
        OneCount++;
      }
      bitVec[idx] = 1;
      inverseVec[idx] = 0;
    }
    
    void unfix(int idx) {
      if (bitVec[idx] == 1) {
        OneCount--;
      }
      bitVec[idx] = 0;
      inverseVec[idx] = 1;    
    }
    
    void flip() {
      swap(bitVec,inverseVec);
      OneCount = n - OneCount;
    }
    
    bool all() {
      return OneCount == n;
    }
    
    bool one() {
      return OneCount >= 1;
    }
    
    int count() {
      return OneCount;
    }
    
    string toString() {
      string s;
      for (int i = 0; i < n; i++) {
        s += ('0' + bitVec[i]);
      }
      return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */