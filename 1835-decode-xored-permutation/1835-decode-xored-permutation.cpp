class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
      int total = 0;
      int n = encoded.size() + 1;
      vector<int> res(n);
      for (int i = 1; i <= encoded.size() + 1; ++i) {
        total ^= i;
      } // 1^2^3
      int idx = encoded.size()/2;
      int step = 1;
      int tmp = 0;
      while(idx < encoded.size()){ // 0^1 1^2
        tmp = tmp^encoded[idx];
        tmp = tmp^encoded[idx-step];
        idx++;
        step += 2;
        total ^= tmp; // 1^2^3 idx1 idx^3
      }
      res[n/2] = total;
      for(int i = n/2-1; i>=0; --i) {
        res[i] = res[i+1] ^ encoded[i];
      }
      for(int i = n/2+1; i < n; ++i) {
        res[i] = res[i-1] ^ encoded[i-1];
      }
      return res;
    }
};