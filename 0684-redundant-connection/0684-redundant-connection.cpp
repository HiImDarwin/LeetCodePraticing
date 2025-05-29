class Solution {
public:
    // if the two node visited before
    // than if they are from two diff set -> won't have cycle
    // from two same set -> have cycle
    // vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    //     int n=edges.size();    
    //     UnionFind set(n);
    //     for(vector<int> &x : edges) {
    //         int node1 = x[0];
    //         int node2 = x[1];
    //         if(!set.Union(node1,node2)) return x;
    //     }
    //     return {};
    // }

    // struct UnionFind {
    //     vector<int> parent;
        
    //     UnionFind(int n): parent(n+1) {
    //         for(int i=0;i<n+1;i++){
    //             parent[i] = i;
    //         }
    //     }
    //     int find (int x){
    //         if(parent[x]!=x) {
    //             parent[x] = find(parent[x]);
    //         }
    //         return parent[x];
    //     }
    //     bool Union(int x, int y) {
    //         int x_par = find(x);
    //         int y_par = find(y);
    //         if (x_par == y_par) return false;
    //         parent[y_par] = x_par;
    //         return true;
    //     }
    // };

    // ****************** DFS ********************
    // DFS concept is that. Before i add the edge (u,v) into map
    // if u can reach v, than add this may cause cycle
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        for (auto &edge: edges) {
            int u = edge[0], v= edge[1];
            vector<bool> visited(n+1, false); // this for running the DFS
            if (hasPathDFS(graph, u, v, visited)) {
                return edge;
            }
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
    bool hasPathDFS(vector<vector<int>>& graph, int curr, int target, vector<bool> visited){
        if (curr == target) return true;
        visited[curr] = true;

        for(int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                if(hasPathDFS(graph, neighbor, target, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};