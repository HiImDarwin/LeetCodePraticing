class Solution {
public:
    //***************************reverse BFS ************************
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     vector<vector<int>> reverse_adj(graph.size());
    //     vector<int> indegree(graph.size());
    //     for(int i=0;i<graph.size();i++) {
    //         for(auto& node: graph[i]) {
    //             reverse_adj[node].push_back(i);
    //             indegree[i]++;
    //         }
    //     }
    //     vector<int> res;
    //     queue<int> qu;
    //     for(int i=0;i<graph.size();i++) {
    //         if(indegree[i] == 0)  qu.push(i);
    //     }
    //     while(!qu.empty()) {
    //         int node = qu.front();
    //         qu.pop();
    //         res.push_back(node);
    //         for(auto& i:reverse_adj[node] ){
    //             indegree[i]--;
    //             if(indegree[i]==0){
    //                 qu.push(i);
    //             }
    //         }
    //     }
    //     sort(res.begin(),res.end());
    //     return res;
    // }

    //*************************** DFS ************************
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(),false);
        vector<bool> onPath(graph.size(),false);
        vector<int> res;
        for(int i=0;i<graph.size();i++) {
            if(!visited[i]) findSafeNode(graph,i,visited,onPath,res);
        }
        sort(res.begin(),res.end());
        return res;
    }

    bool findSafeNode(vector<vector<int>>& graph,int node, vector<bool>& visited,vector<bool>& onPath,vector<int>& res) {
        visited[node] = true;
        onPath[node] = true;

        for(int& neighbor:graph[node]) {
            if(onPath[neighbor]) return false;
            if(!visited[neighbor] && !findSafeNode(graph,neighbor,visited,onPath,res)){
                return false;
            }
        }
        onPath[node] = false;
        res.push_back(node);
        return true;
    }
};