class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        
        for(auto &link:prerequisites) {
            indegree[link[0]]++;
            adj[link[1]].push_back(link[0]);
        }
        
        queue<int> q;
        for(int i =0; i< numCourses; ++i){
            if(indegree[i] == 0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(auto &x: adj[u]){
                if(--indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return count==numCourses;
    }
};