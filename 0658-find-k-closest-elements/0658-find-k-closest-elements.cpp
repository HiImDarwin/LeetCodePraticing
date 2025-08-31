class Solution {
public:
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     int n = arr.size();
    //     if(n <= k) return arr;
    //     int left = 0, right = n-k; 
    //     // right =  n-k is smaller than the window. 
    //     // But because it's edge case when left = n-k it don't need compare
    //     while(left < right) {
    //       int mid = left + (right - left) / 2;

    //       if(x - arr[mid] <= arr[mid + k] - x) {
    //         right = mid;
    //       } else  {
    //         left = mid+1;
    //       }
    //     }
    //     return vector<int>(arr.begin()+left,arr.begin()+left+k);
    // }


    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int left = 0, right = arr.size() - k;
      while (left < right) {
        int mid = left + (right - left) / 2 ;
        if (x - arr[mid] <= arr[mid + k] - x) {
          right = mid;
        } else if (x - arr[mid] > arr[mid + k] - x) {
          left = mid + 1;
        } else {
          if (x - arr[mid] >= 0) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }
      }
      
      return vector<int> (arr.begin() + left, arr.begin() + left + k);
    }
};



/*

find k  the smallest distance element
 |arr[i]-x|
[2,2,2,2,2,2,2,2,2] x = 3 k = 3 
how to check
return in order

2 way
1. Two pointer + priority queue

2. binary Search + window
[1 2 3 4 5 6 7 8 9 10 11 12 55 89 201]


if k =3
window size is 4
there gona have a window with distance sumup to be minimum (or multi anser)

let the windw size be k+1
compare the first and last element
win = [2,2 2,3,4] x = 1 k = 4
if (abs(win[0] - x) < abs(win[k] -x)) 
this mean the mininum window is on the left side

it will have an edge case that
resout on the cornor
[0,1,2,2,2,3,6,8,8,9] k =5 x = 9
         ^
         left
         right

left and right on thr right side and and is in the right side of window
[{2,3,6,8,8},9] vs [2,{3,6,8,8,9}]


because there are unique element in thr arrry
some time u can't check for result
[1,1,2,2,2,2,2,3,3]
k = 3
x = 3

the first mid window is [2 2 2] if shift left than we are wrong

Question
1. Is the array sorted ?
2. Is the array dulplicate ?
3. if multi answer. should i return the left or right?


*/