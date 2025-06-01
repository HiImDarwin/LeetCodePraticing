class Solution {
public:
    // bool isHappy(int n) {
    //     unordered_set<int> sumUp;
    //     while(true){
    //         int tmp=0;
    //         while(n>0){
    //             int t=n%10;
    //             n = n/10;
    //             tmp = tmp+t*t;
    //         }
    //         if(tmp == 1) return true;
    //         else if (!sumUp.insert(tmp).second) return false;
    //         n = tmp;
    //     }
    //     return false;
    // }
    bool isHappy(int n) {
        int slowpointer = n;
        int fastpointer = nextNum(n);
        while( fastpointer != 1 && slowpointer != fastpointer) {
            slowpointer = nextNum(slowpointer);
            fastpointer = nextNum(nextNum(fastpointer));
        }
        return fastpointer == 1;
    }

    int nextNum(int n ){
        int tmp =0;
        while(n>0){
            int x = n%10;
            n /=10;
            tmp += x*x;
        }
        return tmp;
    }
};