// class Solution {
//   public:
//     int longestSubstring(string s, int k) {
//       int res = 0;
//       for(int charCount = 1; charCount <=26; ++charCount) {
//         res = max(res, helper(s,charCount,k));
//       }
//       return res;
//     }

//     int helper (string& s, int charCount, int k) {
//       int j = 0;
//       unordered_map<char,int> mp;
//       int count = 0; // num for characters whose freq >=k
//       int maxLen = 0;
//       for (int i = 0; i < s.size(); i++) {
        
//         while (j < s.size() && mp.size() <= charCount) {
//           if(++mp[s[j]] ==k) count++;
//           if(mp.size() == charCount && count == charCount) maxLen = (maxLen, j-i+1);
//           j++;
//         }
//         mp[s[i]]--;
//         if(mp[s[i]] == k-1) count--;
//         if(mp[s[i]] == 0) mp.erase(s[i]);
        
//       }
//       return maxLen;
//     }
// };
class Solution {
public:
    int helper(string& s, int t, int k)
    {
        int j = 0;
        unordered_map<char, int>Map;
        int count = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {
            while (j<s.size() && Map.size() <= t)
            {
                Map[s[j]]++;
                if (Map[s[j]]==k)
                    count++;
                j++;

                if (Map.size()==t && count == t)
                    ret = max(ret, j-i);
            }
            
            Map[s[i]]--;
            if (Map[s[i]]==k-1)
                count--;
            if (Map[s[i]]==0)
                Map.erase(s[i]);
        }
        return ret;
    }

    int longestSubstring(string s, int k) 
    {
        int ret = 0;
        for (int t=1; t<=26; t++)
            ret = max(ret, helper(s, t, k));
        return ret;
    }
};
/*
In this question
we can't find a normal way for two pointer because it's hard
to find to stop satuation for right pointer.(when to stop?)

So the way to correct it is set a stop satuation
> the window must contain m different characters 
m = 1 ~26
so the complexity is o(26N)  
*/