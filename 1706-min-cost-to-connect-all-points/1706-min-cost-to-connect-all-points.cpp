class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<int>> linkWeight(points.size());
        DisjointSet nodeSet(points.size());
        vector<bool> addin(points.size(),false);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> qu; // length, node1 index, node2 index
        for(int i=0;i<points.size()-1;i++) {
            for(int j=i+1; j<points.size(); j++) {
                int dis = abs(points[i][0]-points[j][0]) +abs(points[i][1]-points[j][1]);
                qu.push({dis,{i,j}});
            }
        }
        int edgecount=0;
        int res=0;
        while(edgecount < points.size()-1 && !qu.empty()){
            auto edgeweight = qu.top();
            qu.pop();
            if(nodeSet.un(edgeweight.second.first,edgeweight.second.second)) {
                edgecount++;
                res+=edgeweight.first;
            }
        }
        return res;     
    }


    struct DisjointSet {
        vector<int> parent;
        vector<int> rank;
        DisjointSet(int n): parent(n), rank(n,1) {
            iota(parent.begin(),parent.end(),0);

        }
        int find(int x) {
            if(parent[x]!=x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        bool un(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);

            if(root_x == root_y) return false;
            if(rank[root_x]>=rank[root_y]) {
                parent[root_y] =  root_x;
                rank[root_x] += rank[root_y];
            } else {
                parent[root_x] = root_y;
                rank[root_y] += rank[root_x];
            }
            return true;
        }
    };
};