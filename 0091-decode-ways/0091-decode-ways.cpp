class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 or s[0] == '0') return 0;
        //F[n] = F[n-1]+F[n-2]
        vector<int> decode_way(s.length()+1,0);
        decode_way[0]=1; // node num is an decode way too
        decode_way[1]=1;

        for(int i=2; i< s.length()+1;i++){
            if(s[i-2] == '0' && s[i-1] == '0') break;
            if(s[i-1] != '0') decode_way[i] += decode_way[i-1];
            if(s[i-2] == '1' ||( s[i-2] == '2' && s[i-1]<'7')) decode_way[i] += decode_way[i-2];
        }
        return decode_way[s.length()];
    }
};