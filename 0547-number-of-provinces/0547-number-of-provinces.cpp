class Solution {
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<bool> visited(n,false);
        int count = 0;

        for (int i=0; i<n; ++i){
            if(!visited[i]) {
                dfs(isConnected,visited, i);
                count++;
            }
        }
        return count;
        
    }

    void dfs(vector<vector<int>>& map, vector<bool> &visited, int index) {       
        visited[index] = true;
        for(int j=0; j< map.size();j++) {
            if(map[index][j] == 1 && !visited[j]) {
                dfs(map,visited,j);
            }
        }
    }


// //*********************Union Find**********************
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         unordered_set<int> provinces;

//         UnionFind UFset(n);
//         for(int i=0;i<n;i++) {
//             for(int j = 0; j<n; j++) {
//                 if(i==j) continue;
//                 if(isConnected[i][j]==1){
//                     UFset.unite(i,j);
//                 }
//             }
//         }
//         for(int i=0;i<n;i++) {
//             provinces.insert(UFset.find(i));
//         }
//         return provinces.size();
//     }
// private:
//     struct UnionFind {
//         vector<int> parent;
//         vector<int> rank;

//         UnionFind(int n): parent(n) {
//             for( int i=0; i< n; i++) parent[i] = i;
//         }

//         int find(int x) {
//             return parent[x] == x ? x : parent[x] = find(parent[x]);
//         }

//         bool unite(int x, int y) {
//             int rx = find(x);
//             int ry = find(y);
//             if(rx == ry) return false;
//             parent[ry] = rx;
//             return true;
//         }
//     };
};

