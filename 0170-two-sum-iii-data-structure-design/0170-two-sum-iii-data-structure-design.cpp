class TwoSum {
    unordered_map<int,int> element;
public:
    TwoSum() {

    }
    
    void add(int number) {
       element[number]++;
    }
    
    bool find(int value) {
      for(auto a: element){
        long target = (long)value - a.first;
        if(target == a.first) {
          if (a.second > 1) return true;
          else continue;
        } 
        if(element.find(target)!=element.end()) {
          return true;
        }
      }
      return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */