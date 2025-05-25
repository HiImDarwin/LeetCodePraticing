class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if (memo.find(n) ==memo.end()) {
            memo[n]=climbStairs(n-1)+climbStairs(n-2);
        }
        return memo[n];
    }
private:
    unordered_map<int,int> memo;
};