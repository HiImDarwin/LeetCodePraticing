class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> tmp;
        for(auto &trip: trips) {
            int st= trip[1];
            int end= trip[2];
            int num= trip[0];
            if(tmp.count(st)) {
                tmp[st] += num;
            } else {
                tmp[st] = num;
            }
            if(tmp.count(end)) {
                tmp[end] -= num;
            } else {
                tmp[end] = (-num);
            }
        }
        int num=0;
        for(auto& x:tmp) {
            num += x.second;
            if(num>capacity) return false;
        }
        return true;
    }
};