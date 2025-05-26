class Solution {
public:
    bool divisorGame(int n) {
        return n%2==0;
    }
    // bool divisorGame(int n) {

    //     vector<int> res(n+1);
    //     res[1] = 0;
    //     // Find the factors of each number
    //     int index = 2;
    //     while (index <= n) {
    //         vector<int> factorSet = gotfector(index);
    //         res[index] = 0;
    //         for(int &x: factorSet) {
    //             if(res[index-x]%2 == 0) {
    //                 res[index] = res[index-x]+1;
    //                 break;
    //             }
    //         }
    //         index++;
    //     }
    //     return res[n]%2 == 0 ? false: true;
    // }

    // vector<int> gotfector(int n) {
    //     vector<int> res{1};
    //     for(int i=2; i*i <=n; i++) {
    //         if (n%i==0) {
    //             res.push_back(i);
    //             if (i != n/i) res.push_back(n/i);
    //         }
    //     }
    //     return res;
    // }
};

        // every number have a best solution already
        // in your turn, u must choose the number need odd steps
        // use bottom up way to calculate to n


        // 4 -1> 3 -1> 2 -1> 1 2step than loss
        // 4 -2> 2 -1> 1.      3 step than win
        // 5 -5> 4.            4 step
        // 6 -1> 5.            5
        // 6 -2> 4             4
        // 6 -3> 3             3
        // 8 (1,2,4)
        // 8 -1> 7 -1> 6 ->

        // edge condition
        // what happen if n = 1? this condition should not happen