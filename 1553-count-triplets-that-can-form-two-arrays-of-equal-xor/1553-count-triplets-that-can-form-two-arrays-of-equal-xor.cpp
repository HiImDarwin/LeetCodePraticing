class Solution {
public:
    int countTriplets(vector<int>& arr) {
      int n = arr.size();
      vector<int> prefix(n+1);
      prefix[0] = 0;
      for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] ^ arr[i-1];
      }
      int res = 0;
      for (int j = 1; j < n; j++) {
        unordered_map<int,int> count;
        for (int i = j-1; i >= 0; --i) {
          count[prefix[i]^prefix[j]]++;
        }
        for (int k = j+1; k <= n; ++k) {
          int target = prefix[j]^prefix[k];
          if (count.find(target)!= count.end()) {
            res += count[target];
          }
        }
      }
      return res;
    }
};

/*

XXXXXXXXX
 j
brute force O(n^3)
fix i j find j k
for  len 1 ~ n-1
  for i = 0


memo
if a == b 
a^b = 0;
    





*/