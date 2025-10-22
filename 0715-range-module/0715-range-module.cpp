class RangeModule {
public:
    RangeModule() { }
    
    void addRange(int left, int right) {
      auto it = rangeSet.upper_bound(left);

      while (it != rangeSet.end() && it->first <= right) {
        right = max(it->second, right);
        ++it;
        rangeSet.erase(prev(it));
      }

      if (it != rangeSet.begin() && left <= (--it)->second) {
        it->second = max(it->second, right);
      } else {
        rangeSet[left] = right;
      }

    }
    
    bool queryRange(int left, int right) {
      auto it = rangeSet.upper_bound(left);
      if (it == rangeSet.begin()) return false;
      return prev(it)->second >= right;
    }
    
    void removeRange(int left, int right) {
      auto it = rangeSet.lower_bound(left);
      int cutEnd = -1;

      while(it != rangeSet.end() && it->first < right) {
        cutEnd = max(cutEnd, it->second);
        ++it;
        rangeSet.erase(prev(it));
      }

      if (it != rangeSet.begin() && (--it)->second > left) {
        cutEnd = max(cutEnd,  it->second);
        it->second = left;
      }

      if (right < cutEnd) {
        rangeSet[right] = cutEnd;
      }
        
    }


  private:
    map<int, int> rangeSet;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */


 /*
      -----------     -----------
    [.  ]
        [      ]
              [.  ]
                 [ ]
              [        ]
 */