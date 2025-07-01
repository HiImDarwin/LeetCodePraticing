class Solution {
public:
    int numberOfSubstrings(string s) {
      int n = s.length();
      vector<int> freq(3,0);
      int count = 0;
      int res = 0;
      int j = 0;
      for(int i = 0; i < n; i++) {
        if(freq[s[i]-'a']++ == 0) {
          count++;
        }
        if(count == 3) {
          res += n - i;
        }
        while(j < i && count == 3) {
          if(--freq[s[j]-'a'] == 0) {
            count--;
          } else {
            res += n-i;
          }
          j++;
        }
      }
      return res;
    }
};


/*

minimim window is when a b c appear once
for each window we find the right  possible substring for it
x x x [a x b c] x x x x 
       i     j          n

the n -j is num of substring for this window


the question is how about the left side of the window ?
already been count by the window on left


there is an corner case i didn't concern
[aaabc] when left move right [aabc] [abc] also can build valid substring
*/