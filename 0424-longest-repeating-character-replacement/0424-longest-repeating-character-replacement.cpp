class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==0) return 0;
        vector<int> letter(26,0);
        //window size right-left+1
        int maxLength=0;
        int leading=0; //give any char

        int left=0,right=0;
        while(right<s.length()){
            int idx = s[right]-'A';
            
            letter[idx]++;
            leading = (letter[idx]>=letter[leading]) ? idx: leading;
            if(right-left+1 > letter[leading]+k){
                while(s[left] == leading){
                    letter[s[left]-'A']--;
                    left++;
                }
                letter[s[left]-'A']--;
                left++;
            }

            maxLength = max(maxLength,right-left+1);
            right++;
        }

        return maxLength;
    }
};