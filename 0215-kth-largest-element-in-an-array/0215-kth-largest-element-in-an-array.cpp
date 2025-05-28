class Solution {
public:
    //************* priority queue way ****************//
    //
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHp(nums.begin(),nums.end());
        for(int i=1;i<k;i++) {
            maxHp.pop();
        } 
        return maxHp.top();
    }
    //*************** arrry heap *********************//
    // int findKthLargest(vector<int>& nums, int k) {
    //     for(int i = nums.size()/2-1;i>=0;i--) {
    //         heapify(nums, i);
    //     }
    //     for(int i = 1; i<k; i++) {
    //         nums[0] = nums.back();
    //         nums.pop_back();
    //         heapify(nums, 0);
    //     }
    //     return nums[0];
       
    // }
    // void heapify(vector<int>& nums , int root) {
    //     int N = nums.size();
    //     while(true) {
    //         int biggest = root;
    //         int l = root*2+1;
    //         int r = root*2+2;

    //         if(l<N &&nums[biggest]<nums[l]) biggest = l;
    //         if(r<N &&nums[biggest]<nums[r]) biggest = r;
    //         if(biggest == root) break;

    //         swap(nums[biggest],nums[root]);
    //         root = biggest;
    //     }
    // }

    //*************** quick sort *********************//
    // super slow
//     int findKthLargest(vector<int>& nums, int k) {
//         int left = 0, right = nums.size()-1, kth;
//         while(true) {
//             int idx = partition(nums,left,right);
//             if(idx == k-1) {
//                 kth = nums[k-1];
//                 break;
//             }
//             if(idx < k-1) {
//                 left = idx+1;
//             } else {
//                 right = idx-1;
//             }
//         }
//         return kth;
        
//     }

// private: 
//     int partition(vector<int>& nums, int left, int right) {
//         int pivot = nums[left];
//         int l = left+1;
//         int r = right;
//         while(l<=r) {
//             while(l <=r && nums[l]>=pivot) l++;
//             while(l <=r && nums[r]<pivot) r--;
//             if(l<r) {
//                 swap(nums[l],nums[r]);
//             }
//         }
//         swap(nums[r],nums[left]);
//         return r;
//     }
};