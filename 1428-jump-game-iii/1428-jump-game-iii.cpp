class Solution {
  vector<bool> visit;
public:
    bool canReach(vector<int>& arr, int start) {
      int n = arr.size();
      visit.resize(n,false);
      queue<int> qu;
      qu.push(start);
      while(!qu.empty()) {
        int pos = qu.front(); qu.pop();
        visit[pos] = true;
        if(arr[pos] == 0) return true;
        if(pos + arr[pos] < n && !visit[pos + arr[pos]]) {
          qu.push(pos + arr[pos]);
        }
        if(pos - arr[pos] >= 0 && !visit[pos - arr[pos]]) {
          qu.push(pos - arr[pos]);
        }
      }
      return false;
    }
};

/*





*/