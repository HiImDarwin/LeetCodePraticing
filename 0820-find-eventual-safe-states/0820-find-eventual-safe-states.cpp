class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> reverse_adj(graph.size());
        vector<int> indegree(graph.size());
        for(int i=0;i<graph.size();i++) {
            for(auto& node: graph[i]) {
                reverse_adj[node].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> res;
        queue<int> qu;
        for(int i=0;i<graph.size();i++) {
            if(indegree[i] == 0)  qu.push(i);
        }
        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();
            res.push_back(node);
            for(auto& i:reverse_adj[node] ){
                indegree[i]--;
                if(indegree[i]==0){
                    qu.push(i);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};