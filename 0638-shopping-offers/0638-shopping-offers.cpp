class Solution {
//   int memo[1<<24];
//   int n;
// public:
//     int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
//       n = price.size();
//       vector<vector<int>> specials;
//       for (int i = 0; i < special.size(); i++) {
//         int sum = 0;
//         for (int j = 0; j < n; ++j) {
//           sum += special[i][j]*price[j];
          
//         }
//         if(sum > special[i].back()) {
//             specials.push_back(special[i]);
//         }
//       }

//       int state = 0;
//       for (int i = 0; i < n; ++i) {
//         state += needs[i] << (i * 4);
//       }

//       return dfs(state, price, specials);
//     }

//     int dfs(int state, vector<int>& price, vector<vector<int>>& specials) {
//       if(memo[state] !=0 ) return memo[state];

//       int res = 0;
//       for (int i = 0; i < n; ++i) {
//         res += (state>>(i*4))%16 * price[i];
//       }

//       for (auto comb : specials) {
//         int flag = 1;
//         for (int i = 0; i < n; ++i) {
//           if ((state>>(i*4))%16 < comb[i]) {
//             flag = 0;
//             break;
//           }
//         }
//         if (flag == 0) continue;

//         int state2 = state;
//         for (int i = 0; i < n; ++i) {
//           state2 -= comb[i]*(1<<(i*4));
//         }
//         res = min(res, comb[n] + dfs(state2, price, specials));
//       }

//       memo[state] = res;
//       return res;
//     }
  map<vector<int>,int> mp;
public: 
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    if (mp.find(needs) != mp.end()) return mp[needs];
    int ans = 0;
    for(int i = 0; i < needs.size(); i++) {
      ans += needs[i]*price[i];
    }

    for(vector<int> &offer : special) {
      bool valid = true;
      for (int i = 0; i < needs.size(); ++i) {
        if (needs[i] < offer[i]) {
          valid = false;
          break;
        }
      }
      if(valid) {
        vector<int> tmp = needs;
        for(int i = 0; i < needs.size(); i++) {
          tmp[i] -= offer[i];
        }
        ans = min(ans, offer.back() + shoppingOffers(price, special, tmp));
      }
    }
    return mp[needs] = ans;

  }
};

/*

total price : 
discount


comnplexity O(2^k * n^2)
*/