class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n+1);
        res[0] = 0;
        res[1] = 0;
        //res[2] = min(res[0]+cost[0],res[1]+cost[1]);
        int index=2;
        while(index <= n) {
            res[index] = min(res[index-2]+cost[index-2],res[index-1]+cost[index-1]);
            index++;
        }
        return res[n];
    }
};