class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n=matrix[0].size(),ans;
        priority_queue<vector<int>,vector<vector<int>>, greater<>> minHp;
        for(int r=0;r<min(m,k);++r) {
            minHp.push({matrix[r][0],r,0});
        }
        for (int i=1; i <= k; ++i) {
            auto top = minHp.top(); minHp.pop();
            int r = top[1],c = top[2];
            ans = top[0];
            if (c+1<n) minHp.push({matrix[r][c + 1], r, c + 1});
        }
        return ans;
    }
};