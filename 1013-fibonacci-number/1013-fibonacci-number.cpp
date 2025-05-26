class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        vector<int> res(n+1,-1);
        res[0] = 0;
        res[1] = 1;
        return fib(n,res);
    }
    int fib(int n, vector<int> &arr) {
        if (arr[n-1] == -1) arr[n-1] = fib(n-1,arr);
        if (arr[n-2] == -1) arr[n-2] = fib(n-2,arr);
        arr[n] = arr[n-1]+arr[n-2];
        return arr[n];
    }
};