class Solution {
public:
    // long long numOfSubsequences(string s) {
    //   int n = s.length();
    //   vector<vector<long long>> memo(n+1,vector<long long>(4,0));
    //   long long total = 0;
      
    //   for (int i = 1; i <= n; ++i) {
    //     memo[i][0] = memo[i-1][0];
    //     memo[i][1] = memo[i-1][1];
    //     if(s[i-1] == 'L') {
    //       memo[i][0]++;
    //     } else if (s[i-1] == 'C') {
    //       memo[i][1] += memo[i][0];
    //     } else if (s[i-1] == 'T') {
    //       total += memo[i][1];
    //     }
    //     //cout <<  memo[i][0] << " " << memo[i][1] << endl;
    //   }
    //   //cout << "total " << total << endl;
    //   for (int i = n-1; i >= 0 ; --i) {
    //     memo[i][2] = memo[i+1][2];
    //     memo[i][3] = memo[i+1][3];
    //     if(s[i] == 'T') {
    //         memo[i][3]++;
    //     } else if (s[i] == 'C') {
    //         memo[i][2] += memo[i][3];
    //     }
    //     //cout <<  memo[i][2] << " " << memo[i][3] << endl;
    //   }
      
    //   long long maxIncrease = 0;
    //   for (int i = 0; i <= n; i++) {
    //     long long ifL = memo[i][2];
    //     long long ifC = memo[i][0] * memo[i][3];
    //     long long ifT = memo[i][1];
    //     //cout << memo[i][0] << " " << memo[i][1] << " " <<  memo[i][2] << " " << memo[i][3] << endl;
    //     //cout << ifL << " " << ifC << " " <<  ifT << endl;
    //     maxIncrease = max({maxIncrease, ifL, ifC, ifT});
    //   }
    //   //cout << "maxIncrease " << maxIncrease << endl;
    //   return total + maxIncrease;
    // }


    long long numOfSubsequences(string s) {
      int n = s.length();
      long long ctCount = 0;
      long long tCount = 0;
      for (int i = n-1; i >= 0; i--) {
        if(s[i] == 'T') {
          tCount++;
        } else if (s[i] == 'C') {
          ctCount += tCount;
        }
      }

      long long lCount = 0, lcCount = 0;
      long long total = 0, extra = 0; 
      extra = ctCount;

      for (int i = 0; i < n; i++) {
        if(s[i] == 'L') {
          lCount++;
          total += ctCount;
        } else if (s[i] == 'C') {
          ctCount -= tCount;
          lcCount += lCount;
        } else if (s[i] == 'T') {
          tCount--;
        }
        long long addL = ctCount;
        long long addC = lCount * tCount;
        long long addT = lcCount;
        extra = max({extra, addL, addC, addT});
      }
      return total + extra;
    }


};

/*

L CC LL TTT CC T



at each position you need to know the leagel C and T behind you
T LC組合會再翻倍
C 前面的L 與後面的T可以跟我搭配
L 後面的CT組合會再翻倍

紀錄L > forward
紀錄LC > forward

紀錄CT < backward
紀錄T < backward

*/