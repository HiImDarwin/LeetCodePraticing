class Solution {
public:
    string freqAlphabets(string s) {
      string res;
      for(int i = s.length()-1; i >=0; --i) {
        if(s[i] == '#') {
          int num = stoi(s.substr(i-2,2));
          res = char('a' + num - 1) + res;
          i -= 2;
        } else {
          res = char('a' + (s[i] - '1')) + res;
        }
      }
      return res;
    }
};