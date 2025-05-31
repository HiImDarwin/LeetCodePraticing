class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> dist(n,INF);
        dist[src]=0;
        for(int i=0;i<=k;i++) {
            //bellman ford relax need to base on previous round
            vector<int> prev = dist;
            for(auto& f: flights) {
                int u=f[0];
                int v=f[1];
                int w=f[2];
                if(prev[u]!= INF && prev[u]+w < dist[v]){
                    dist[v] = prev[u]+w;
                }
            }
        }
        return (dist[dst] == INF) ? -1 : dist[dst];
    }
};