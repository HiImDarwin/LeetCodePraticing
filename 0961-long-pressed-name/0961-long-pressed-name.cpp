class Solution {
public:
    bool isLongPressedName(string name, string typed) {
      vector<pair<char,int>> block;
      int i = 0;
      while (i < name.length()) {
        char c = name[i];
        int count = 1;
        while (i+1 < name.length() && name[i+1] == c) {
          i++;
          count++;
        }
        block.push_back({c,count});
        i++;
      }
      int j = 0, k = 0;
      while (j < block.size() && k < typed.length()) {
        if(typed[k] != block[j].first) {
          return false;
        } else {
          int count = 1;
          while (k+1 < typed.length() && typed[k+1] == typed[k]) {
            count++;
            k++;
          }
          if (count <  block[j].second) {
            return false;
          }
        }
        k++;
        j++;
      }
      if (k < typed.length() || j < block.size()) return false;
      return true;
       
    }
};