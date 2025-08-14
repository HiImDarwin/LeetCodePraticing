class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
      vector<int> count(32);
      long long total = 0;
      long long res = 0;
      for(int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < 32; j++) {
          if ((nums[i]>>j) & 1) {
            count[j]++;
          }
        }
        total |= nums[i];
      }


      for (int i = 0; i < nums.size(); i++) {
        auto tmpCount = count;
        long long tmpTotal = total;
        for (int j = 0; j < 32; j++) {
          if ((nums[i]>>j) & 1){
            tmpCount[j]--;
            if(tmpCount[j] == 0) {
              tmpTotal ^= (1<<j);
            }
          }
        }
        tmpTotal |= ((long long)nums[i] << k);
        res = max(res, tmpTotal);
      }
      return res;
    }
};

/*
1. 越高位是1月好
2. 越多bit是1越好

最重要的資訊 >> k不會拆開來用

找出所有最高位1都成立的
先算一個所有最高位1的set
將set以外的node先做or


更加解
因為你不能反向取消 bit or operation
但你可以統計每個 bit position 有幾個1 
然後先將所有的num 做一次 or
*/