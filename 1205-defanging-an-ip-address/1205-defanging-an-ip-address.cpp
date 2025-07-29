class Solution {
public:
    string defangIPaddr(string address) {
      string res;
      stringstream ss;
      ss << address;
      string tmp;
      while(getline(ss, tmp, '.')) {
        res += tmp;
        res += "[.]";
      }
      return res.substr(0, res.length()-3);
    }
};