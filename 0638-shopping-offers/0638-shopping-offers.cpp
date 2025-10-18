class Solution {
  public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
      int n = price.size();
      int mask = 0;
      for (int i = 0; i < n; i++) {
        mask += (needs[i] << i * 4);
      }
      if (mp_.find(mask) != mp_.end()) {
        return mp_[mask];
      }
      int amount = 0;
      for (int i = 0; i < n; i++) {
        amount += needs[i] * price[i];
      }

      for (auto& s : special) {
        bool valid = true;
        vector<int> new_needs = needs;
        for (int i = 0; i < n; i++) {
          if (new_needs[i] < s[i]) {
            valid = false;
            break;
          }
          new_needs[i] -=  s[i];
        }

        if (valid) {
          int offerCost = shoppingOffers(price, special, new_needs) + s[n];
          amount = min(amount, offerCost);
        }
      }

      return mp_[mask] = amount;
    }
  private:
    unordered_map<int,int> mp_;
};
/*
  dp -> not easy to write


  recursive


  state
    each element for 4 bit



*/