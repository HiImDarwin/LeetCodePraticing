class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.empty()) return 0;
        int count=0;
        int leftPar =0;
        for(char &x : s) {
            if(x == '('){
                leftPar++;
            } else {
                if(leftPar <= 0) count++;
                else leftPar--;
            }
        }
        return count+leftPar;
    }
};