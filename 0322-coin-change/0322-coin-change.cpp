class Solution {
public:
    // f(n) = min( f(n-a')+1,f(n-a'')+1,f(n-a''')+1,...)
    //*******************topdown********************
    // int coinChange(vector<int>& coins, int amount) {
    //     unordered_map<int,int> dp_map;
    //     dp_map[0] = 0;
    //     return dp(coins,amount,dp_map);
    // }
    // int dp(vector<int>& coins, int amount, unordered_map<int,int> &dp_map) {
    //     if(amount <0) return -1;
    //     if(amount == 0) return 0;
    //     if(dp_map.count(amount)) return dp_map[amount];
        
    //     int min_count = INT_MAX;
    //     for(const int &coin:　coins) {
    //         int res = dp(coins, amount -coin, dp_map);
    //         if( res>=0 && res < min_count) {
    //             min_count = res+1;
    //         }
    //     }
    //     dp_map[amount] = (min_count == INT_MAX) ? -1 : min_count;
    //     return dp_map[amount];
    // }

    //***********bottom up********************
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1);
        dp[0] = 0;
        for(int i=1;i<amount+1;i++) {
            int min=INT_MAX;
            for(auto &coin:coins) {
                if (i-coin < 0) break;
                if(dp[i-coin] >= 0 && dp[i-coin]+1 < min) min = dp[i-coin]+1;
            }
            dp[i] = (min==INT_MAX)? -1 : min;
        }
        return dp[amount];
    }

};