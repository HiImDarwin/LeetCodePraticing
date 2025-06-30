class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
      int n = boxes.size(), m = warehouse.size();
      sort(boxes.begin(), boxes.end());
      int right = m-1, left = 0, idx = n-1;
      int res = 0;
      for (int i = n - 1; i >= 0; --i) {
        if(left > right) break;
        if(warehouse[left] >= boxes[i] ) {
          res++;
          left++;
        } else if (warehouse[right] >= boxes[i] ) {
          right--;
          res++;
        }
      }
      return res;
    }
};



/*
find the pivot point

*/