class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int lenS = s.length()-1;
        int lenT = t.length()-1;
        while (lenS >= 0 && lenT >= 0) {
          handleBackSpace(s, lenS);
          handleBackSpace(t, lenT);
          if (lenS >= 0 && lenT >= 0) {
            if (s[lenS] != t[lenT]) {      
              return false;
            }
            cout << s[lenS] << " ";
            lenS--;
            lenT--;
          } 
        }

        if (lenS >= 0) {
          handleBackSpace(s, lenS);
        }
        if (lenT >= 0) {
          handleBackSpace(t, lenT);
        }

        return (lenS < 0 && lenT < 0) ? true : false;
    }
    void handleBackSpace(const string& str, int& idx) {
      int count = 0;
      while (idx >= 0 && (str[idx] == '#' || count > 0)) {
        if (str[idx] == '#') {
          count++;
        } else {
          count--;
        }
        idx--;
      }
    }
};