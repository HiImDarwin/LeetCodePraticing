class Solution {
  // unordered_map<int> memo;
  vector<vector<int>> possibleSet;
public:
    vector<int> minDifference(int n, int k) {
      vector<int> factor;
      recursive(n ,k, 1, factor);
      int minIdx = -1;
      int minVal = INT_MAX;
      for (int i = 0; i < possibleSet.size(); ++i) {
        if (possibleSet[i].back() - possibleSet[i][0] < minVal) {
          minVal = possibleSet[i].back() - possibleSet[i][0] ;
          minIdx = i;
        }
      }
      return possibleSet[minIdx];
    }

    void recursive(int n, int k, int minIdx, vector<int>& factor) {
      if (k == 0 && n != 1) {
        return;
      } else if (k == 0 && n == 1) {
        possibleSet.push_back(factor);
        return;
      }
      for (int i = minIdx; pow(i,k) <= n; ++i) {
        if (n % i != 0) continue;
        factor.push_back(i);
        recursive(n/i, k - 1, i , factor);
        factor.pop_back();
      }
    }
};

/*
100
1 2 5 10 20 50 100

num^k <= n
1 100
2 50
4 25
5 20
10 10

1 1 44
1 2 22
1 4 11

2 2 11


*/