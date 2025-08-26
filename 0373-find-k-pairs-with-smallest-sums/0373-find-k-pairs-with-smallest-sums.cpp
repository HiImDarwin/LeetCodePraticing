class Solution {
public:
    // vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    //   priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,less<>> pq;
    //   int m = nums1.size();
    //   int n = nums2.size();
    //   vector<vector<int>> res;
      
    //   for (int i = 0;  i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //       if (pq.size() < k) {
    //         pq.push({nums1[i] + nums2[j], i, j});
    //       } else if (pq.size() == k && nums1[i] + nums2[j] >= get<0>(pq.top())) {
    //         break;
    //       } else if (pq.size() == k && nums1[i] + nums2[j] < get<0>(pq.top())) {
    //         pq.pop();
    //         pq.push({nums1[i] + nums2[j], i, j});
    //       }  
    //     }
    //   }
    //   while (!pq.empty()) {
    //     auto [num, i, j] = pq.top();
    //     pq.pop();
    //     res.push_back({nums1[i],nums2[j]});
    //   }
    //   return res;
    // }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      int m = nums1.size();
      int n = nums2.size();

      vector<vector<int>> ans;
      set<pair<int, int>> visited;

      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                      greater<pair<int, pair<int, int>>>> minHeap;
      minHeap.push({nums1[0] + nums2[0], {0, 0}});
      visited.insert({0, 0});

      while (k-- && !minHeap.empty()) {
          auto top = minHeap.top();
          minHeap.pop();
          int i = top.second.first;
          int j = top.second.second;

          ans.push_back({nums1[i], nums2[j]});

          if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
              minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
              visited.insert({i + 1, j});
          }

          if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
              minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
              visited.insert({i, j + 1});
          }
      }
      return ans;
    }
};





/*
在連續區間找第K個
這就是 binary search 的起手式
*/