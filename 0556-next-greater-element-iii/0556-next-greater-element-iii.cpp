class Solution {
public:
    int nextGreaterElement(int n) {
      string num = to_string(n);
      int i = num.length()-2;
      while(i >= 0 &&　num[i] >= num[i+1]) i--;
      if(i < 0) return -1;

      int j = num.length()-1;
      while(num[j] <= num[i]) j--;
      swap(num[i], num[j]);
      sort(num.begin() + i + 1, num.end());

      long newNum = stol(num);
      return newNum > INT_MAX ? -1 : (int)newNum;
    }
};