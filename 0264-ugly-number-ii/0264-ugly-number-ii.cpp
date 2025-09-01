class Solution {
public:
    int nthUglyNumber(int n) {
      set<long long> numSet;
      
      numSet.insert(1);
      int count = 0;
      for (auto& num : numSet) {
        count++;
        if (count == n) return num;
        numSet.insert(num * 2);
        numSet.insert(num * 3);
        numSet.insert(num * 5);
      }
    
      return 0; 
    }
};


/*
2 4 6 10
3 9 15
5 25

12 18 30
20 30 50
55
25
125
*/