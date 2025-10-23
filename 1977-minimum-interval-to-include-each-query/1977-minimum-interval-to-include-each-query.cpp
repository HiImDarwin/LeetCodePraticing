class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
      sort(intervals.begin(), intervals.end());
      vector<pair<int, int>> query;
      for (int i = 0; i < queries.size(); i++) {
        query.push_back({queries[i], i});
      }
      sort(query.begin(), query.end());
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
      int j = 0;
      vector<int> res(queries.size(), -1);
      for (auto& [num, idx] : query) {
        while (j < intervals.size() && num >= intervals[j][0]) {
          pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
          j++;
        }
        while (!pq.empty() && pq.top().second < num) {
          pq.pop();
        }
        if (!pq.empty()) {
          res[idx] = pq.top().first;
        }
      }
      return res;
    }
};