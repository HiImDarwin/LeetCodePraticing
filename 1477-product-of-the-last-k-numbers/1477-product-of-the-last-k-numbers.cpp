class ProductOfNumbers {
    vector<long long> preMul;
    int zeroPos;
public:
    ProductOfNumbers() {
      preMul.push_back(1);
      zeroPos = INT_MAX/3;
    }
    
    void add(int num) {
      if (num == 0) {
        zeroPos = 0;
        preMul.clear();
        preMul.push_back(1);
      } else {
        preMul.push_back(num * preMul.back());
      }
      zeroPos++;
    }
    
    int getProduct(int k) {
      if (k >= zeroPos) return 0;
      int n = preMul.size();
      return preMul[n-1]/preMul[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */