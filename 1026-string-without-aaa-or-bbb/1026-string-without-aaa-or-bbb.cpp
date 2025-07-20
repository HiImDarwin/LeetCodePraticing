class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string strA = "a";
        string strB = "b";
        string res;
        while(a > 0 && b > 0) {
          if(a > b) {
            res += strA + strA;
            res += strB;
            a-=2;
            b-=1;
          } else if(a == b) {
            res += strA + strB;
            a--;
            b--;
          } else {
            res += strB+strB;
            res += strA;
            a-=1;
            b-=2;
          }
        }
        while(a > 0) {
          res += strA;
          a--;
        }
        while(b > 0) {
          res += strB;
          b--;
        }
        return res;
    }
};