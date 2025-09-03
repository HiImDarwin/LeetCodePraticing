class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
      int len = s.length();
      long long oneCount = 0 , zeroCount = 0;
      map<pair<int,int>,long long> mp;
      mp[{0, 0}] = 1;
      long long res = 0;
      for (const auto& c : s) {
        if (c == '1') {
          oneCount++;
        } else {
          zeroCount++;
        }

        int k = min(zeroCount/num1, oneCount/num2);
        long long x = zeroCount - k * num1;
        long long y = oneCount - k * num2;
        if (mp.find({x, y}) != mp.end()) {
          res += mp[{x,y}];
        }
        mp[{x, y}]++;
      }

      return res;
    }
};

/*
substring 
conting 0 and 1
prefix sum


1:3
2:6
3:9

*/