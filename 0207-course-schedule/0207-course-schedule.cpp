class Solution {
public:
    //******************************BFS***********************************
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> indegree(numCourses,0);
    //     vector<vector<int>> adj(numCourses);
        
    //     for(auto &link:prerequisites) {
    //         indegree[link[0]]++;
    //         adj[link[1]].push_back(link[0]);
    //     }
        
    //     queue<int> q;
    //     for(int i =0; i< numCourses; ++i){
    //         if(indegree[i] == 0) q.push(i);
    //     }
    //     int count=0;
    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();
    //         count++;
    //         for(auto &x: adj[u]){
    //             if(--indegree[x] == 0){
    //                 q.push(x);
    //             }
    //         }
    //     }
    //     return count==numCourses;
    // }
    //
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        for(auto& link: prerequisites) {
            adj[link[1]].push_back(link[0]);
        }
        vector<bool> onPath(numCourses, false); //this is for checking cycle
        for(int i=0; i<numCourses;i++){
            if(!visited[i]) {
                if(hasCycle(i, adj, visited, onPath)) return false;
            }
        }
        return true;
    }

    bool hasCycle(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& onPath) {
        visited[u] = true;
        onPath[u] = true;
        for (int v: adj[u]){
            if(!visited[v]) {
                if(hasCycle(v,adj,visited,onPath)) return true;
            } else if ( onPath[v]) {
                return true;
            }
        }
        onPath[u] = false;
        return false;
    }
};