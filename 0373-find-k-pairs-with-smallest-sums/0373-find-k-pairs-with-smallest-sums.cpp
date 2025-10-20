class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      int n = nums1.size();
      int m = nums2.size();

      vector<int> idx(n, 0); 
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
      for (int i = 0; i < n; i++) {
        pq.push({nums1[i] + nums2[idx[i]], i});
      }

      vector<vector<int>> res;
      while (!pq.empty() && k-- > 0) {
        auto [sum, idx_1] = pq.top();
        pq.pop();
        res.push_back({nums1[idx_1], nums2[idx[idx_1]]});
        if (++idx[idx_1] < m) {
          pq.push({nums1[idx_1] + nums2[idx[idx_1]], idx_1});
        }
      }

      return res;
    }
};

/*
{1,1} {1,2} {1,3} {1, 4} 
{2,1} {2,2} {2,3} {2, 4}
{3,1} {3,2} {3,3} {3, 4} 

*/
