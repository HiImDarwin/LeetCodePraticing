class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto &pre: prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> res;
        queue<int> qu;
        
        for(int i=0; i<numCourses; i++) {
            if(indegree[i]==0) {
                qu.push(i);
            }
        }
        //BFS
        while(!qu.empty()) {
            int node = qu.front();
            res.push_back(node);
            qu.pop();
            //check adj
            for(auto &adj_node: adj[node]) {
                if(--indegree[adj_node]==0){
                    qu.push(adj_node);
                }
            }
        }
        return (res.size() == numCourses) ? res : vector<int>{};
    }
};