class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char,int> mp;
        int maxDist = 0;
        for (char& c : s) {
          mp[c]++;
          int maxEdit = abs(mp['E'] - mp['W']) +  abs(mp['S'] - mp['N']) + 
                        2 * min(min({mp['E'], mp['W'], k}) + min({mp['S'], mp['N'], k}), k);
          maxDist = max(maxDist, maxEdit);
        }
        return maxDist;
    }
};


/*

  record preSum of E W S N
  abs(E-W) + abs(S-N) + max(min(E,W,k),min(S,N,k))


*/