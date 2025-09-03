class Solution {
  struct smaller {
    bool operator() (const pair<double,int> &a,const pair<double,int> &b) {
      return a.first < b.first;
    }
  };
public:
    // double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    //   priority_queue<pair<double,int>,vector<pair<double,int>>,smaller> pq;

    //   for(int i = 0 ;i < classes.size(); i++) {
    //     double pass = classes[i][0];
    //     double total = classes[i][1];
    //     double delta = (pass+1)/(total+1) - pass/total;
    //     pq.push({delta, i});
    //   }

    //   while(extraStudents) {
    //     auto [delta, index] = pq.top();
    //     pq.pop();
    //     classes[index][0]++;
    //     classes[index][1]++;
    //     double pass = classes[index][0];
    //     double total = classes[index][1];
    //     double del = (pass+1)/(total+1) - pass/total;
    //     pq.push({del, index});
    //     extraStudents--;
    //   }
    //   double res = 0;
    //   for(auto cla : classes) {
    //     res += 1.0*cla[0]/cla[1];
    //   }
    //   res /= (double)classes.size();

    //   return res;
    // }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
      priority_queue<pair<double, int>> pq;
      
      for (int i = 0; i < classes.size(); i++) {
        int pass = classes[i][0];
        int total = classes[i][1];
        double delta =  1.0 * (pass + 1) / (total + 1) - 1.0 * (pass) / (total);
        pq.push({delta, i});
      }

      while (extraStudents > 0) {
        auto [delta, cla] = pq.top();
        pq.pop();
        extraStudents--;
        int pass = ++classes[cla][0];
        int total = ++classes[cla][1];
        double newDelta =  1.0 * (pass + 1) / (total + 1) - 1.0 * (pass) / (total);
        pq.push({newDelta, cla});
      }

      double res = 0;
      for (int i = 0; i < classes.size(); i++) {
          int pass = classes[i][0];
          int total = classes[i][1];
          res += 1.0 * (pass) / (total);
      }
      return res/classes.size();
    }
};

/*

each class pass rate passi/total

priority queue<pair<double, i>> pq

passi + 1 /total + 1 - passi/total
average pass ratio = sum(class pass)/classNum


*/