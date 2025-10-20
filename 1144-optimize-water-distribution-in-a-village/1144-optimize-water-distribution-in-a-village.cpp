class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
      vector<vector<pair<int,int>>> adj(n + 1);
      for (auto& pipe : pipes) {
        int house1 = pipe[0];
        int house2 = pipe[1];
        int cost = pipe[2];
        adj[house1].push_back({cost, house2});
        adj[house2].push_back({cost, house1});
      }

      priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
      for (int i = 0; i < n; i++) {
        pq.push({wells[i],i + 1});
      }

      unordered_set<int> visited;
      int totalCost = 0;

      while (!pq.empty()) {
        auto [cost, house] = pq.top();
        pq.pop();
        if (visited.count(house)) {
          continue;
        }
        visited.insert(house);
        totalCost += cost;
        if (visited.size() == n) {
          break;
        }
        for (pair<int, int>& nei : adj[house]) {
          if (visited.count(nei.second)) {
            continue;
          }
          pq.push(nei);
        }
      }
      return totalCost;
    }
};

/*
build first well with minimun cost wells
put all wells in queue


*/