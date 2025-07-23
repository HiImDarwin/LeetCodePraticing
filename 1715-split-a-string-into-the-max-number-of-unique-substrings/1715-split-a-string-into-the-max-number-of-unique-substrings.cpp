class Solution {
public:
    int maxUniqueSplit(string s) {
      int left = 1;
      int right =  s.length();
      unordered_set<string> subStrSet;
      while(left < right) {
        int mid = right - (right - left) / 2;
        subStrSet.clear();
        if(isValid(s, mid, 0, subStrSet)) {
          left = mid;
        } else {
          right = mid-1;
        }
      }
      return left;
    }
    bool isValid (const string s, int substringNum, int index, unordered_set<string> &subStrSet) {
      if(index == s.length()) return false;
      if(substringNum == 1 && subStrSet.count(s.substr(index)) == 0) return true;

      if(s.length() - index < substringNum) return false;

      for(int i = index, j = index+1 ;j < s.length() ; j++) {
        if(subStrSet.count(s.substr(i,j-i)) == 0) {
          subStrSet.insert(s.substr(i,j-i));
          if(isValid(s, substringNum - 1, j,subStrSet)) return true;
          subStrSet.erase(s.substr(i,j-i));
        }
      }
      return false;
    }
};


/*
backtracking


binary search + valid check



*/