class Solution {
public:
    // int peakIndexInMountainArray(vector<int>& arr) {
    //     int right = arr.size()-1;
    //     int left =0;
    //     while(left <= right) {
    //         int mid = left+(right-left)/2;
    //         if((mid == arr.size()-1 || arr[mid] > arr[mid+1]) && (mid ==0 || arr[mid] >arr[mid-1])) return mid;
    //         else if((mid ==0 || arr[mid-1] < arr[mid]) &&  arr[mid] < arr[mid+1]) { //accessending
    //             left = mid+1;
    //         } else if ( arr[mid-1] >arr[mid] && (mid == arr.size()-1  ||arr[mid] > arr[mid+1])) { //decessending
    //             right = mid-1;
    //         }
    //     }
    //     return -1; //dummy 
    // }

    int peakIndexInMountainArray(vector<int>& arr) {
        int right = arr.size()-1;
        int left = 0;
        
        while (left <right) {
            int mid = left +(right-left)/2;
            if(arr[mid] < arr[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};