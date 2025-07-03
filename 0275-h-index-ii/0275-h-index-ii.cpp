class Solution {
public:
    // int hIndex(vector<int>& citations) {
    //   int n = citations.size();
    //   if(n == 0 || citations[n-1] == 0) return 0;
    //   int right = n-1;
    //   int left = 0;
        
    //   while(left < right) {
    //     int mid  = left+ (right-left) / 2;
    //     if(citations[mid] >= (n - 1) - mid + 1) {
    //       right = mid;
    //     } else {
    //       left = mid + 1;
    //     }
    //   }

    //   return n-left;
    // }

  int hIndex(vector<int>& citations) {
    int n = citations.size();
    int i;
      for(i = 1; i <=n; i++) {
        if(citations[n-i] < i)
          break;
      }
      return i-1;
  }
};




/*
the array is an non-descending order
[ 1 1 1 2 2 3 4 5 6 10 12 19 ]
             mid          n-1

maximum value of h paper citied more than h times
whe are seaching for the minimon num[i] >= n-i+1; 
(when we go left and n-i+1 go bigger and num[i] go smaller)

And there i an condition that no thsis esixt for this
[0 0 0 0 0 0 0]


Ther got to be a easier way
*/