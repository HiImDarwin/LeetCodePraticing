class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int front=0;
        int end=0;
        while(front < intervals.size()) {
            vector<int> tmp;
            end = front+1;
            int biggest=intervals[front][1];
            
            while(end <intervals.size() && biggest>=intervals[end][0]){
                biggest = max(biggest,intervals[end][1]);
                end++;
            }

            tmp.push_back(intervals[front][0]);
            tmp.push_back(biggest);
            front = end;
            res.push_back(tmp);
        }
        return res;
    }
};