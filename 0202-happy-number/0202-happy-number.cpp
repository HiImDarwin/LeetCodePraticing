class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sumUp;
        while(true){
            int tmp=0;
            while(n>0){
                int t=n%10;
                n = n/10;
                tmp = tmp+t*t;
            }
            if(tmp == 1) return true;
            else if (!sumUp.insert(tmp).second) return false;
            n = tmp;
        }
        return false;
    }
};