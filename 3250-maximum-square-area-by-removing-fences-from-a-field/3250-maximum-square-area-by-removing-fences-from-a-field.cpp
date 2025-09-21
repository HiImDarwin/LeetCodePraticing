class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
      
      hFences.push_back(1);
      hFences.push_back(m);
      sort(hFences.begin(), hFences.end());
      vFences.push_back(1);
      vFences.push_back(n);
      sort(vFences.begin(), vFences.end());

      unordered_set<int> length;
      for (int i = 1; i < hFences.size(); i++) {
        for (int j = 0; j < i; j++) {
          length.insert(hFences[i]-hFences[j]);
        }
      }
      int res = INT_MIN;
      for (int i = 1; i < vFences.size(); i++) {
        for (int j = 0; j < i; j++) {
          int len = vFences[i] - vFences[j];
          if (length.find(len) != length.end()) {
            res = max(res, len);
          }
        } 
      }

      return res == INT_MIN ? -1 : (1LL * res * res) % (int)(1e9+7);
    }
};


/*
return  maximum area of a square field 

1 ~ m
1 ~ n
brute force O(min(m,n)^3) 
for (every len) 
  for (fix row) 
    for (fix col)

    find all x width possibility
    find all y width possibility
    sort both width
    two pointer

duplicate width

360000



binarySearch (wrong) -> 沒有單調性 某個長度有沒解 不代表更長沒有解
*/