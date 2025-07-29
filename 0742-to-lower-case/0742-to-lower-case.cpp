class Solution {
public:
    string toLowerCase(string s) {
      for(char &c : s) {
        if( c >= 'A' && c <= 'Z') {
          c = tolower(c);
        }
      }
      return s; 
    }
};