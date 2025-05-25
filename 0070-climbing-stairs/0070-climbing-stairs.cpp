//TOP-DOWN DP
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==1) return 1;
//         if(n==2) return 2;
//         if (memo.find(n) ==memo.end()) {
//             memo[n]=climbStairs(n-1)+climbStairs(n-2);
//         }
//         return memo[n];
//     }
// private:
//     unordered_map<int,int> memo;
// };


class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2) return 2;
        int method[n];
        method[0]=1;
        method[1]=2;
        for(int i=2;i<n;i++) {
            method[i] = method[i-1]+method[i-2];
        }
        return method[n-1];
    }
};