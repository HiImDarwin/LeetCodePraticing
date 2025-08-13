class Solution 
{
  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
      int n = s.length();
      int m = pairs.size();
      vector<int> group(n);
      iota(group.begin(),group.end(),0);

      auto find = [&](auto&& self, int x) -> int {
        if (group[x] != x) {
          group[x] = self(self, group[x]);
        }
        return group[x];
      };

      auto unite = [&](int a, int b) -> void {
        int u = find(find, a);
        int v = find(find, b);
        if (u == v) return;
        if (u < v) {
          group[v] = u;
        } else {
          group[u] = v;
        }
      };

      for (auto& pair : pairs) {
        int x = pair[0], y = pair[1];
        unite(x, y);
      }

      unordered_map<int,vector<char>> charGroup;

      for (int i = 0; i < n; i++) {
        int g = find(find, i);
        charGroup[g].push_back(s[i]);
      }
      for (auto& [group, vec] : charGroup) {
        sort(vec.begin(), vec.end());
      }

      vector<int> groupIndex(n, 0);

      for (int i = 0; i < n; i++) {
        s[i] = charGroup[group[i]][groupIndex[group[i]]];
        groupIndex[group[i]]++;
      }

      return s;
    }
};
/*


find the group of each char
  iterator pairs O(m)
  union index
used a vector to store each group element 
sort each group
O(n) + O(n log n)

used  vector for each group index

O
*/