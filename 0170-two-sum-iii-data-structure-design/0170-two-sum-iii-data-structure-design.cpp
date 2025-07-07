class TwoSum {
    unordered_set<long> element;
    unordered_set<long> sumUp;
public:
    TwoSum() {

    }
    
    void add(int number) {
        for(const long &x : element) {
          sumUp.insert(x+(long)number);
        }
        element.insert((long)number);
    }
    
    bool find(int value) {
      return  sumUp.count(value);
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */