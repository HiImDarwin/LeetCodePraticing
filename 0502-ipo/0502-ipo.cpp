class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      vector<pair<int,int>> project;
      priority_queue<int> pq;

      for(int i = 0; i < capital.size(); ++i) {
        project.push_back({capital[i],i});
      }
      sort(project.begin(),project.end());
      vector<pair<int,int>>::iterator prev_index = project.begin();
      vector<pair<int,int>>::iterator it = project.begin();
      while(k--) {
        it = upper_bound(it, project.end(), w, [](const int& w, const pair<int,int> &a) {
          return w < a.first;
        });
        while(prev_index != it) {
          pq.push(profits[prev_index -> second]);
          prev_index++;
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