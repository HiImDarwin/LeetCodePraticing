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
        if(element.find((long)value - a.first) != element.end()) {
          if((long)value - a.first == a.first) {
            if(a.second > 1 )
              return true;
          } else {
            return true;
          }
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