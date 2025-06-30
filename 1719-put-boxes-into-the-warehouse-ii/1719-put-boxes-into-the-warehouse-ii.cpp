class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
      int m = warehouse.size();
      int n = boxes.size();
      sort(boxes.begin(), boxes.end());
      
      int right = m-1, left = 0, idx = n-1;
      int res = 0;
      while(left <= right && idx >= 0) {
        if(warehouse[right] > warehouse[left]) {
          while(idx >= 0 && boxes[idx] > warehouse[right]) 
            idx--;
          if(idx < 0) break;
          idx--;
          right--;
          res++;
        } else {
          while(idx >= 0 && boxes[idx] > warehouse[left] ) 
            idx--;
          if(idx < 0) break;
          idx--;
          left++;
          res++;
        }
      }
      return res;
    }
};



/*
find the pivot point

*/