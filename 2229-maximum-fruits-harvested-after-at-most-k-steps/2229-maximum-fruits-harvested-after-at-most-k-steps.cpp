class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
      vector<int> preSumLeft(k + 1), preSumRight(k + 1);
      unordered_map<int,int> mp;
      for (auto& fruit : fruits) {
        mp[fruit[0]] = fruit[1];
      }
      int sum = 0;
      for (int i = 0; i <= k; i++) {
        sum += mp[startPos - i];
        preSumLeft[i] = sum;
      }

      sum = 0;
      for (int i = 0; i <= k; i++) {
        sum += mp[startPos + i];
        preSumRight[i] = sum;
      }

      int res = max(preSumLeft[k], preSumRight[k]);
      for (int i = 0; i <= k ; i++) {
        res = max(res, preSumLeft[i] + preSumRight[(k - i) / 2] - mp[startPos]);
      }
      for (int i = 0; i <= k; i++) {
        res = max(res, preSumRight[i] + preSumLeft[(k - i) / 2] - mp[startPos]);
      }

      return res;

    }
};

/*
dp

go left go right

preSumLeft[k]
preSumRight[k]
Originleft[k]
Originright[k]
2x + 

*/