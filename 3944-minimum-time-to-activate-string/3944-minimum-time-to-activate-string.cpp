class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
      if(k == 0) return 0;
      int n = order.size();
      set<pair<int,int>> segments;
      segments.insert({0,n-1});
      int res = 0;
      long long count = 0;
      for(int i = 0; i < n; ++i) {
        s[order[i]] = '*';
        auto it = segments.upper_bound({order[i],INT_MAX});
        if(it != segments.begin()) {
          it--;
        }
        auto [l, r] = *it;
        segments.erase(it);
        segments.insert({l,order[i]-1});
        segments.insert({order[i]+1, r});

        count += 1LL * (order[i]- l + 1) * (r - order[i] + 1);

        if(count >= k) return res;
        res++;
      }
      return -1;
    }
};