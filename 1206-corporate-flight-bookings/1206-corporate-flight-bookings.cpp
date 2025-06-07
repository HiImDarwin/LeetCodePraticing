class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);
        for(auto x:bookings) {
            int i = x[0];
            int m = x[1];
            int num = x[2];
            while(i<=m){
                res[i-1] +=num;
                i++;
            }
        }
        return res;
    }
};