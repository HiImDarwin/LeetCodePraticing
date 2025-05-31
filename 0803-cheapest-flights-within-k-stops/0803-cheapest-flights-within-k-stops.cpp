class Solution {
public:
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     const int INF = 1e9;
    //     vector<int> dist(n,INF);
    //     dist[src]=0;
    //     for(int i=0;i<=k;i++) {
    //         //bellman ford relax need to base on previous round
    //         vector<int> prev = dist;
    //         for(auto& f: flights) {
    //             int u=f[0];
    //             int v=f[1];
    //             int w=f[2];
    //             if(prev[u]!= INF && prev[u]+w < dist[v]){
    //                 dist[v] = prev[u]+w;
    //             }
    //         }
    //     }
    //     return (dist[dst] == INF) ? -1 : dist[dst];
    // }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight: flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        // (cost, current node, steps)
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,src,0});

        vector<int> stops(n,INT_MAX); //each node less stops

        while(!pq.empty()) {
            auto [cost,node,step] = pq.top();
            pq.pop();

            if(node == dst) return cost;
            if(step>k ||step >=stops[node]) continue;
            stops[node] = step;

            for(auto[neighbor, price] : adj[node]) {
                pq.push({cost+price,neighbor,step+1});
            }
        }
        return -1;
    }
};