class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,less<>> pq;
      int m = nums1.size();
      int n = nums2.size();
      vector<vector<int>> res;
      
      for (int i = 0;  i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (pq.size() < k) {
            pq.push({nums1[i] + nums2[j], i, j});
          } else if (pq.size() == k && nums1[i] + nums2[j] >= get<0>(pq.top())) {
            break;
          } else if (pq.size() == k && nums1[i] + nums2[j] < get<0>(pq.top())) {
            pq.pop();
            pq.push({nums1[i] + nums2[j], i, j});
          }  
        }
      }
      while (!pq.empty()) {
        auto [num, i, j] = pq.top();
        pq.pop();
        res.push_back({nums1[i],nums2[j]});
      }
      return res;
    }
};





/*
在連續區間找第K個
這就是 binary search 的起手式
*/