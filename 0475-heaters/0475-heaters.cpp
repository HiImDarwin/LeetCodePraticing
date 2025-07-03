class Solution {
  public:
    // int findRadius(vector<int>& houses, vector<int>& heaters) {
    //   sort(houses.begin(),houses.end());
    //   sort(heaters.begin(), heaters.end());
    //   int m  = houses.size();
    //   int n  = heaters.size();
    //   int res = 0;
    //   for(int i = 0, j =0; i < m; ++i) {
    //     int tmp = abs(houses[i] - heaters[j]);
    //     while(j+1 < n && abs(houses[i] - heaters[j+1]) <= tmp) {
    //       j++;
    //       tmp = abs(houses[i] - heaters[j]);
    //     }
    //     res = max(res, tmp);
    //   }
    //   return res;
    // }


    int findRadius(vector<int>& houses, vector<int>& heaters) {
      sort(heaters.begin(), heaters.end());
      int res = 0;
      for(int house : houses) {
        int r;
        auto iter = lower_bound(heaters.begin(), heaters.end(), house);
        if(iter == heaters.end()) {
          r = house - *prev(iter,1);
        } else if(iter == heaters.begin()) {
          r = *iter - house;
        } else {
          r = min(house - *prev(iter,1), *iter-house); 
        }
        res = max(res,r);
      }
      return res;
    }
};



/*

x   x   x  x   x        x  x          house
---------------------------
h  h      h   h   h    h   h          heater

the qeustion is to find the maximum 
range for a house to nearest heater


This can go with two pointer

fixed each house
iterat the  heater
find the shortest distant for a house to heater 
compare the min range

TimeComplexity
O(N log N) + O(M log M) + O(N) +O(M)


 question
 number of house
 range of house distance and heater dist
 complexity limit

*/


/*

for each house, find the lower bound position  and the upper bound pos
nearby the house
find the minimum distance between them.

so in this case. you need to sort the heater

Time complexity
O(nlog n) + O(m log n)

*/