class Solution {
public:
    // char findTheDifference(string s, string t) {
    //     vector<int> bucket(26,0);

    //     for(char &c:t ) {
    //         bucket[c-'a']++;

    //     }
    //     for(char& c:s) {
    //         bucket[c-'a']--;
    //     }

    //     for(int i=0;i<26;i++){
    //         if(bucket[i]!=0) return i+'a';
    //     }
    //     return 'c'; // dummy
    // }

    // useing ascii num
    char findTheDifference(string s, string t) {
        int ans=0;
        for(int i=0; i<s.size(); i++) {
            ans -=s[i];
            ans += t[i];
        }
        ans+=t[s.size()];
        return ans;
    }
};