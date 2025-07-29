class Solution {
public:
    string reverseWords(string s) {
      s += ' ';
      size_t n = s.find(' ');
      size_t start = -1;
      while(n!= string::npos) {
        reverse(s.begin()+start+1, s.begin()+n);
        start = n;
        n = s.find(' ',start+1);
      }
      s.pop_back();
      return s;
    }
    // string reverseWords(string s) {
    //     string res;
    //     stringstream ss;
    //     ss << s;
    //     string tmp;
    //     while(ss >> tmp) {
    //       reverseString(tmp);
    //       res += tmp;
    //       res += " ";
    //     }
    //     if(!res.empty()) res.pop_back();
    //     return res;
    // }

    // void reverseString(string &s) {
    //   int i = 0, j = s.length()-1;
    //   while (i<j) {
    //     swap(s[i],s[j]);
    //     i++;
    //     j--;
    //   }
    // }
};