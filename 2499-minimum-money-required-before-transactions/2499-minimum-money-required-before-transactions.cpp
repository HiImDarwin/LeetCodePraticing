class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
      int n = transactions.size();
      sort(transactions.begin(), transactions.end(), cmp);
      long long hisLow = 0;
      long long currMoney = 0;
      long long positiveMaxCost = 0;
      for (int i = 0; i < n; ++i) {

        long long cost = transactions[i][0], cashback = transactions[i][1];
        if (cost <= cashback) {
          positiveMaxCost = max(positiveMaxCost, cost);
        } else {
          currMoney -= cost;
          hisLow = min(hisLow, currMoney);
          currMoney += cashback;
        }
      }
      currMoney -= positiveMaxCost;
      hisLow = min(hisLow, currMoney);
      return abs(hisLow);
    }

private:
  static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
  }
};

/*
主要讓虧錢的時候，最後剩的錢越多 代表你前期投資要越多。
最後剩的錢是多少？  cashbacki
所以你的排序應該是 



money = money - costi + cashbacki
money > costi
cashback - cost = profit


[1][2][3][-5]
*/