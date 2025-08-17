class Solution {
    int visited[1<<21];
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        int totalSum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if (totalSum < desiredTotal) return false;
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }

    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal)
    {
        if (visited[state]==2)
            return true;
        if (visited[state]==1)
            return false;

        for (int i=1; i<=maxChoosableInteger; i++)
        {
            if ((state>>i)&1) continue;
            if (sum+i >= desiredTotal) return true;
            
            if (dfs(state+(1<<i), sum+i, maxChoosableInteger, desiredTotal)==false)
            {
                visited[state] = 2;
                return true;
            }                
        }
        visited[state] = 1;
        return false;
    }
};
// class Solution {
//   unordered_map<int,bool> memo;
// public:
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
//       return dfs(0, 0, maxChoosableInteger, desiredTotal);
//     }

//     bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal) {
//       if (memo.find(state) != memo.end()) {
//         return memo[state];
//       }

//       for (int i = 1; i <= maxChoosableInteger; i++) {
//         if ((state >> i) & 1) continue;
//         if (sum + i >= desiredTotal) return true;
//         if (dfs(state + (1 << i), sum + i, maxChoosableInteger, desiredTotal) == false) {
//           memo[state] = true;
//           return true;
//         }
//       }
//       memo[state] = false;
//       return false;
//     }
// };

/*
思路
  雙方決策差異只在參數 並且不斷往目標值去
  應該用遞歸來模擬雙方的決策選擇過程

  遞歸怎麼設計
  1. 目前值＋可用值 >= target 就return true
  2. 使用目前值傳給對方 若對方回傳true 就表示我不能用這個值
  3. 若所有值都不能用 就是return false;

  狀態壓縮
如果對手返回必贏 那麼當前這個數值我就不能選





時間複雜度怎麼計算
  如果沒有用memo每次都會徹底跑完 O(20!)


  因為你沒辦法從for 去看出來 有些會跳過 有些呼叫會直接return
  那實際上真的有運算的總共是 O(2^20) 
  因為你有20bit 所有狀態都會跑一次
*/