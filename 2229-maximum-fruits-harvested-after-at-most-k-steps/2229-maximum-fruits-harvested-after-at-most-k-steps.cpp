class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
      vector<int> preSumLeft(k + 1), preSumRight(k + 1), OriginLeft(k + 1), Originright(k + 1);
      unordered_map<int,int> mp;
      for (auto& fruit : fruits) {
        mp[fruit[0]] = fruit[1];
      }
      int sum = 0;
      for (int i = 0; i <= k; i++) {
        sum += mp[startPos - i];
        preSumLeft[i] = sum;
        if (i * 2 <= k) {
          OriginLeft[i*2] = sum;
        }
      }

      sum = 0;
      for (int i = 0; i <= k; i++) {
        sum += mp[startPos + i];
        preSumRight[i] = sum;
        if (i * 2 <= k) {
          Originright[i*2] = sum;
        }
      }

      int res = max(preSumLeft[k], preSumRight[k]);
      for (int i = 1; i <= k / 2; i++) {
        res = max(res, OriginLeft[i * 2] + preSumRight[k - (i * 2)] - mp[startPos]);
      }
      for (int i = 1; i <= k / 2; i++) {
        res = max(res, Originright[i * 2] + preSumLeft[k - (i * 2)] -  mp[startPos]);
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

*/