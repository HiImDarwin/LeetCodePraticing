class Solution {
public:
    // vector<int> pathInZigZagTree(int label) {
    //   stack<int> st;
    //   vector<int> res;
    //   int depth = 1;
    //   int original = 1, mirror = 1;
    //   res.push_back(1);
    //   int height = 1;
    //   while(label >= pow(2,height)) {
    //     height++;
    //   }
    //   if (height%2 == 0) {
    //     int y = pow(2,height)-1 - label;
    //     label = pow(2,height-1) + y;
    //   }
    //   while(label > 1) {
    //     st.push(label & 1);
    //     label = label >> 1;
    //   }
    //   while(!st.empty()) {
    //     int way = st.top(); st.pop();
    //     if(way == 0) {
    //       original = original * 2;
    //       mirror = mirror * 2 + 1;
    //     } else {
    //       original = original * 2 + 1;
    //       mirror = mirror * 2;
    //     }
    //     if(++depth%2 == 0) {
    //       res.push_back(mirror);
    //     } else {
    //       res.push_back(original);
    //     }
    //   }
    //   return res;
    // }
    vector<int> pathInZigZagTree(int label) {
      vector<int> path;
      while(label > 0) {
        path.push_back(label);
        int x = log2(label) + 1; // get the height
        int max = (1 << x) - 1;
        int min = (1 << (x-1));
        label = (min + max-label) / 2; //find the mirror parent
      }
      reverse(path.begin(),path.end());
      return path;
    }
};


/*

triverse tree from mirror route and take the node from two route
in even level take the mirror node
in the odd level take the original route node
how to count out the original route
use stack store the binary bit of label


          1
     3          2
  4     5     6    7
15 14 13 12 11 10 9 8 



case 1 label in odd line >　calculate as normal
case 2 label in even line > mirror the label num

*/