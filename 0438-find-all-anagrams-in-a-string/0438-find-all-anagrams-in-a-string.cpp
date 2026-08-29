class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int wLen = p.length();
    unordered_map<int,int> mp;
    for(char &c : p) {
      mp[c]++;
    }
    int count = mp.size();
    vector<int> res;
    int idx = 0;

    while (idx < s.length()) {
      if (idx >= wLen) {
        if (mp.find(s[idx - wLen]) != mp.end()) {
          mp[s[idx - wLen]]++;
          if (mp[s[idx - wLen]] == 1) {
            count++;
          }
        }
      }

      if (mp.find(s[idx]) != mp.end()) {
        mp[s[idx]]--;
        if (mp[s[idx]] == 0) {
          count--;
        }
      }

      if (count == 0) {
        res.push_back(idx - wLen + 1);
      }

      idx++;
    }
    return res;
  }
};

/*
remove element idx = n
strat count  idx = n - 1;
*/