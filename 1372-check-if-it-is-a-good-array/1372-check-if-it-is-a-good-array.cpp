class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
       
        int gcdNum = nums[0];
        for (int& n : nums) {
          gcdNum = gcd(gcdNum,n);
        }
        return gcdNum == 1;

    }
};


/*

假設我們取三個數n1 n2 n3 並且乘任意數k1 k2 k3

n1*k1 + n2*k2 + n3*k3 = 1

如果三個相乘數可以找出公約數b b>1 ，那麼他們的和必定是 b的倍數 不會是1
n1`*k1`*b + n2`*k2`*b + n3`*k3`*b = b*k4

找出一個subarry 最大公約數 = 1
因此只需要找出兩個數互質 或是整組最大公約數為1

中國剩餘定理


*/