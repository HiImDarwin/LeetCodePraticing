class Solution {
public:
    bool reorderedPowerOf2(int n) {
      string nStr= to_string(n);
      sort(nStr.begin(), nStr.end());
      
      for (int i = 0; i < 32 ;i++) {
        string valStr = to_string(1<<i);
        sort(valStr.begin(), valStr.end());
        if (nStr == valStr) return true;
      }
      return false;
        
    }
};