class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < n-1) return -1;
        vector<bool> noOutDegree(n+1,false);
        vector<int> trustNum(n+1,0);
        for(auto &tru: trust) {
            noOutDegree[tru[0]] = true;
            trustNum[tru[1]]++;
        }
        int res = -1;
        for(int i = 1; i< n+1;i++) {
            if (noOutDegree[i]==false && res == -1 && trustNum[i] == n-1) {
                res = i;
            } else if(noOutDegree[i]==false && res!=-1 ) {
                return -1;
            }
        }
        return res;
    }
};