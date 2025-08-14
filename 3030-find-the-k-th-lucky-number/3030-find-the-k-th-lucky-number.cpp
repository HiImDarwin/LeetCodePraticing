class Solution {
public:
    string kthLuckyNumber(int k) {
      int x = k+2-1;
      string res;
      while (x > 1) {
        if (x & 1) {
          res += '7';
        } else {
          res += '4';
        }
        x = x>>1;
      }
      reverse(res.begin(), res.end());
      return res;
    }
};

/*
0 1 無法代表有效代表 因為他的leading 0開始
因此我們從 
10開始
10->4
11->7
100->44
101->47
110->74
111->77 


*/