class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
      s = s.substr(1,s.length()-2);
      vector<string> res;
      for (int i = 1; i < s.length(); i++) {
        vector<string> a = check(s.substr(0,i));
        vector<string> b = check(s.substr(i));
        if (!a.empty() && !b.empty()) {
          for (auto x:a) {
            for (auto y:b) {
              res.push_back("(" + x + ", " + y + ")");
            }
          }
        }
      }
      return res;
    }

    vector<string> check(string s) {
      int n = s.length();
      vector<string> res;
      if (n == 1 || s[0] != '0') {
        res.push_back(s);
      }
      for (int i = 1; i < n; i++) {
        string a = s.substr(0,i);
        string b = s.substr(i);
        if (a.size() > 1 && a[0] == '0') continue;
        if (b.back() == '0') continue;
        res.push_back(a + "." + b);
      }
      return res;
    }
};




/*
xxxxx
0   n-1 n

(1)
n = 5
insert ", " between  2 and n - 2

if "0" and lenght more than one > not illegal
if 0.0 without other number ending  > illegal
"." 



*/