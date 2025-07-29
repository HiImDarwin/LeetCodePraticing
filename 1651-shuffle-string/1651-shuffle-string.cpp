class Solution {
public:
    // string restoreString(string s, vector<int>& indices) {
    //   string res = s;
    //   for(int i = 0; i < s.length(); ++i) {
    //     res[indices[i]] = s[i];
    //   }
    //   return res;
    // }
    string restoreString(string s, vector<int>& indices) {
      for (int i = 0; i < s.length(); ++i) {
        while(indices[i] != i) {
          swap(s[i], s[indices[i]]);
          swap(indices[i],indices[indices[i]]);
        }
      }
      return s;
    }
};