class Solution {
public:
    string reorganizeString(string s) {
      int n = s.length();
      unordered_map<char,int> mp;
      for(char c: s) {
        mp[c]++;
      }

      priority_queue<pair<int,char>> pq;
      pair<int,char> cooldown = {0,'a'};
      for(auto [c, amount] : mp) {
        if (amount > (n + 1) / 2) return "";
        pq.push({amount,c});
      }
      string res;
      while(!pq.empty()) {
        auto [amount, c] = pq.top();
        pq.pop();
        res += c;
        if(cooldown.first > 0){
          pq.push(cooldown);
        }
        cooldown = {amount - 1, c};

      }
      if(cooldown.first != 0) return "";
      return res;
    }
};