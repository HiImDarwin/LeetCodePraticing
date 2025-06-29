class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int> freq;
        int sLen = s.length();
        int avgCharNum = sLen/4; 
        for(char c: s) {
         freq[c]++;
        }
        if(freq['Q'] == avgCharNum && freq['W'] == avgCharNum && freq['E'] == avgCharNum)
          return 0;

        int res = INT_MAX;
        for(int left = 0,right = 0;right < sLen; ++right) {
          if(--freq[s[right]] != avgCharNum) continue;
          if( freq['Q'] <= avgCharNum && 
              freq['W'] <= avgCharNum && 
              freq['E'] <= avgCharNum &&
              freq['R'] <= avgCharNum ) {
            
            while(left <= right) {
              if(++freq[s[left]] > avgCharNum) {
                res = min(res, right -left+1);
                left++;
                break;
              }
              left++;
            }
          }
        }
        return res;

    }
};