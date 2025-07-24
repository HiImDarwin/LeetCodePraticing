class Solution 
{
  private:
    int n;
    vector<int> maxVisit;
  public:
    int maxJumps(vector<int>& arr, int d) 
    {
      n = arr.size();
      maxVisit.resize(n,-1);
      int res = 0;
      for(int i = 0; i < n; ++i) {
        res = max(res,dfs(arr, i, d));
      }
      return res;
    }

    int dfs(vector<int>& arr, int index, int range) {
      if(maxVisit[index] != -1) {
        return maxVisit[index];
      }
      int maxVisitNum = 0;
      for(int delta = 1; delta <= range; ++delta) {
        int nextPos = index + delta;
        if(nextPos >= n || arr[nextPos] >= arr[index]) break;
        maxVisitNum = max(maxVisitNum, dfs(arr, nextPos, range));
      }
      for(int delta = 1; delta <= range; ++delta) {
        int nextPos = index - delta;
        if(nextPos < 0 || arr[nextPos] >= arr[index]) break;
        maxVisitNum = max(maxVisitNum, dfs(arr, nextPos, range));
      }
      return maxVisit[index] = maxVisitNum + 1;
    }
};



/*
At pos i
we want to go to pos j
 i-j <= d && arr[j] < arr[i] 
[6,4,14,6,8,13,9,7,10,6,12]




*/