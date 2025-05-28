class Solution {
public:
    // f(n) = min( f(n-a')+1,f(n-a'')+1,f(n-a''')+1,...)
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> dp_map;
        dp_map[0] = 0;
        return dp(coins,amount,dp_map);
    }
    int dp(vector<int>& coins, int amount, unordered_map<int,int> &dp_map) {
        if(amount <0) return -1;
        if(amount == 0) return 0;
        if(dp_map.count(amount)) return dp_map[amount];
        
        int min_count = INT_MAX;
        for(const int &coin:　coins) {
            int res = dp(coins, amount -coin, dp_map);
            if( res>=0 && res < min_count) {
                min_count = res+1;
            }
        }
        dp_map[amount] = (min_count == INT_MAX) ? -1 : min_count;
        return dp_map[amount];
    }

};