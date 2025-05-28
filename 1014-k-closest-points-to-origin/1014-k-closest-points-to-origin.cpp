class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cusCompare> minHp;
        for(int i=0; i<points.size(); i++) {
            minHp.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            pair<int,int> node = minHp.top();
            minHp.pop();
            res.push_back(points[node.second]);
        }
        return res;
    }
    struct cusCompare {
        bool operator() (const pair<int,int> x,const pair<int,int> y) const {
            return x.first > y.first;
        }
    };
};