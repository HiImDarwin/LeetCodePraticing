class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //distance vector
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        //adj map
        vector<vector<pair<int,int>>> adj(n+1);
        for( auto & edge: times) {
            int u = edge[0], v=edge[1], w=edge[2];
            adj[u].push_back({v,w});
        }
        // priority queue;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        while(!pq.empty()) {
            auto x = pq.top(); 
            pq.pop();
            int dis= x.first;
            int node = x.second;
            if(dis>dist[node]) continue;

            for(auto [u,v] : adj[node]) {
                if(dist[node]+v <dist[u]){
                    dist[u] = dist[node]+v;
                    pq.push({dist[u],u});
                }
            }
        }

        int res = 0;

        for( int i=1; i<=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            res = max(res,dist[i]);
        }
        return res;
    }
};