class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n+1,0);
        for(auto x:bookings) {
            int i = x[0];
            int m = x[1];
            int num = x[2];
            res[i-1] += num;
            res[m] -= num; 
        }
        for(int i=1; i<n;i++) {
            res[i] = res[i]+res[i-1];
        }
        res.pop_back();
        return res;
    }
};