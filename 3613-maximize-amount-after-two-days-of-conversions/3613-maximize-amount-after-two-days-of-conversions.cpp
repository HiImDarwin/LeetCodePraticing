class Solution {
public:
    // double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
    //   unordered_map<string, double> day1,day2;
    //   day1 = findRate(initialCurrency, pairs1, rates1);
    //   day2 = findRate(initialCurrency, pairs2, rates2);
    //   double maxRate = 0;
    //   for (auto& [currency , rate] : day1) {
    //     if (day2.count(currency) && day2[currency] > 0) {
    //       maxRate = max(maxRate, rate / day2[currency]);
    //     }
    //   }
    //   return maxRate;
    // }

    // unordered_map<string, double> findRate(string initialCurrency, vector<vector<string>>& pairs, vector<double>& rates) {
    //   unordered_map<string, vector<pair<string,double>>> adj;
    //   // O(E)
    //   for (int i =0; i < pairs.size(); i++) {
    //     adj[pairs[i][0]].push_back({pairs[i][1], rates[i]});
    //     adj[pairs[i][1]].push_back({pairs[i][0], 1.0/rates[i]});
    //   }
    //   priority_queue<pair<double,string>> qu;
    //   unordered_map<string, double> ratio;
    //   qu.push({1.0,initialCurrency});
    //   while(!qu.empty()) {
    //     auto [r, cur] = qu.top();
    //     qu.pop();  

    //     if (ratio.count(cur)) continue; 
    //     ratio[cur] = r;

    //     for (auto& [nei, w] : adj[cur]) {
    //         qu.push({r * w, nei});
    //     }
    //   }
    //   return ratio;
    // }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
      unordered_map<string, double> best;
      best[initialCurrency] = 1.0;
      bellman(best, pairs1, rates1);
      bellman(best, pairs2, rates2);
      return best[initialCurrency];
    }

    void bellman(unordered_map<string, double>& best, vector<vector<string>>& pairs, vector<double>& rates) {
      for (int relax_iteration = 0; relax_iteration < pairs.size(); relax_iteration++) {
        for (int i = 0; i < pairs.size(); i++) {
          best[pairs[i][1]] = max(best[pairs[i][1]], best[pairs[i][0]] * rates[i]);
          best[pairs[i][0]] = max(best[pairs[i][0]], best[pairs[i][1]] / rates[i]);
        }
      }
    }
};

/*
find two map count the rate for initialCurrency to other currency
we want 
init * day1Rate(init,j) / day2Rate(init,j) = maxixmum

1. make a adj matrix
2. find shortest path to every currency for 2 days
3. find maximum max(day1Rate(init,j) / day2Rate(init,j))


shortest path
dijkstra
floyd warshell
bellman ford

*/