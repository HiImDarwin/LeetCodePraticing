class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> count1(26,0),count2(26,0);
        int n = s1.size();
        
        for(char &x: s1){
            count1[x-'a']++;
        }
        for (int i = 0; i < n; ++i) {
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        
        for(int i=n;i<s2.size();++i){
            count2[s2[i]-'a']++;
            count2[s2[i-n]-'a']--;
            if(count1 == count2) return true;
        }
        return false;
    }
};