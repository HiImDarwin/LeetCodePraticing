class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      vector<pair<int,int>> project;
      priority_queue<int> pq;

      for(int i = 0; i < capital.size(); ++i) {
        project.push_back({capital[i],profits[i]});
      }
      sort(project.begin(),project.end());
      int i = 0;
      while(k--) {
        while(i < profits.size() && project[i].first <= w) {
          pq.push(project[i].second);
          i++;
        }
        if (pq.empty()) break;
        w += pq.top();
        pq.pop();
      }
      return w;
    }
};

/*
maximum final capital
so what we want is maximum tha profit but consider the capital 




*/