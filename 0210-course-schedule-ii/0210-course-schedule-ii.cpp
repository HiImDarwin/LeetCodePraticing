class Solution {
public:
    //************************BFS+indrgree************************
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> indegree(numCourses,0);
    //     vector<vector<int>> adj(numCourses);
    //     for(auto &pre: prerequisites) {
    //         indegree[pre[0]]++;
    //         adj[pre[1]].push_back(pre[0]);
    //     }
    //     vector<int> res;
    //     queue<int> qu;
        
    //     for(int i=0; i<numCourses; i++) {
    //         if(indegree[i]==0) {
    //             qu.push(i);
    //         }
    //     }
    //     //BFS
    //     while(!qu.empty()) {
    //         int node = qu.front();
    //         res.push_back(node);
    //         qu.pop();
    //         //check adj
    //         for(auto &adj_node: adj[node]) {
    //             if(--indegree[adj_node]==0){
    //                 qu.push(adj_node);
    //             }
    //         }
    //     }
    //     return (res.size() == numCourses) ? res : vector<int>{};
    // }
    //*************************DFS+postorder******************************
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        vector<bool> onPath(numCourses,false);
        vector<int> res;

        for(auto& pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0; i<numCourses;i++ ) {
            if(!visited[i]) {
                if(!DFS(adj,i,visited,res,onPath)) {
                    return {};
                }
            }
        }
        reverse(res.begin(),res.end());
        return res.size() == numCourses  ? res : vector<int>{} ; 
    }

    bool DFS(vector<vector<int>> &adj,int node,vector<bool> &visited,vector<int> &res,vector<bool> &onPath) {
        visited[node] = true;
        onPath[node] = true;
        for(auto &next_node: adj[node]) {
            if(onPath[next_node]) return false;
            if(!visited[next_node]) {
                 DFS(adj,next_node,visited,res,onPath);
            }
        }
        onPath[node] = false;
        res.push_back(node);
        return true;
    }
};