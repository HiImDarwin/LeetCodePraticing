class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n);
        prefixXor[0] = arr[0];
        for (int i = 1; i < n; ++i) {
           prefixXor[i] =  prefixXor[i-1] ^ arr[i];
        }
        vector<int> res;
        for (auto& query : queries) {
          int left = query[0];
          int right = query[1];
          int tmp = left > 0 ? prefixXor[left-1] ^ prefixXor[right] : prefixXor[right];
          res.push_back(tmp);
        }
        return res;
    }
};