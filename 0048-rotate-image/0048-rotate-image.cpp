class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int layer = 0; layer<n/2; layer++) {
            int first = layer;
            int last = n-1-layer;
            for(int i=0; i<last-first;i++){
                int tmp = matrix[first][first+i];
                matrix[first][first+i] = matrix[last-i][first];
                matrix[last-i][first] = matrix[last][last-i];
                matrix[last][last-i] = matrix[first+i][last];
                matrix[first+i][last] = tmp;
            }
        }
    }
};