class Solution {
public:
    // vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    //   multiset<int> set1,set2;
    //   vector<int> res;

    //   for(int i = 0; i< nums.size(); ++i) {
    //     if(set1.size() < x)
    //       set1.insert(nums[i]);
    //     else {
    //       int v = *set1.rbegin();
    //       if(v > nums[i]) {
    //         set1.erase(set1.find(v));
    //         set2.insert(v);
    //         set1.insert(nums[i]);
    //       } else {
    //         set2.insert(nums[i]);
    //       }
    //     }

    //     if(i >= k - 1) {
    //       int v = *set1.rbegin();
    //       res.push_back(min(v,0));

    //       int u = nums[i-k+1];
    //       if(set1.find(u) != set1.end()) {
    //         set1.erase(set1.find(u));
    //         if(!set2.empty()) {
    //           set1.insert(*set2.begin());
    //           set2.erase(set2.begin());
    //         }
    //       } else {
    //         set2.erase(set2.find(u));
    //       }
    //     } 
    //   }
    //   return res;
    // }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
      vector<int> res(nums.size() - k + 1), counter(50);
      for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] < 0) counter[nums[i] + 50]++;
        if(i - k >= 0 && nums[i - k] < 0) counter[nums[i - k] + 50]--;
        if (i - k + 1 < 0) continue;
        for(int j = 0, count = 0; j < 50; ++j) {
          count += counter[j];
          if (count >= x) {
            res[i - k + 1] = j - 50;
            break;
          }
        }
      }
      return res;
    }
};


/*
法一
less than x element <= 0
k element sub array
使用一個 SET 來做sorting並且傳值 > TLE


法一時間複雜度
每次的插入予刪除 O(log n)
每次找第x個元素 O(x) * (n-k+1)
所以最差情況下 O(n log k + n k) 




法二
使用兩個set 省去 查到第x個元素時間
O(n log k)

法三
bucket sort

*/