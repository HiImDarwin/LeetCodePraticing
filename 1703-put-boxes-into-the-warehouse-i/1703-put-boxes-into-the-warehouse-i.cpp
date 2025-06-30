class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) { 
      int n = boxes.size();
      int m = warehouse.size();
      sort(boxes.begin(), boxes.end());
      int minHeight = warehouse[0];
      int i = n - 1;
      int j = 0;
      int res = 0;
      while(i >= 0 && j < m) {
        if(boxes[i] <= warehouse[j]) {
          res++;
          j++;
        } 
        i--;
      }
      return res;
    }
};

/*
push the box from little size
*/