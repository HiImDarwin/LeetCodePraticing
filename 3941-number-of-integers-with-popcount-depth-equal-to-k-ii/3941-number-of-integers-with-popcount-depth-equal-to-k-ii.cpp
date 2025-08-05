class BIT {
  vector<long long> indexTree;
  int n;
  public:
    void init(int n) {
      this -> n = n;
      indexTree.assign(n+1,0);
    }

    bool update(int index, int delta)
    {
      if(index < 1 || index > n) return false; 
      while (index <= n) {
        indexTree[index] += delta;
        index += (index & (-index));
      }
      return true;
    }

    long long query(int right, int left) 
    {
      if (left > right || left < 1 || right > n) return 0;
      return prefixSum(right) - prefixSum(left - 1);
    }

    long long prefixSum (int index) 
    {
      long long result = 0;
      while (index > 0) {
        result += indexTree[index];
        index -= index & (-index);
      }
      return result;
    }
};



class Solution 
{
  public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) 
    {
      int n = nums.size();
      vector<BIT> tree(5);

      for (int i = 0; i < 5; i ++) {
        tree[i].init(n);
      }

      for(int i = 0; i < n; ++i) {
        int depth = getDepth(nums[i]);
        tree[depth].update(i+1, 1);
      }

      vector<int> res; 
      for (auto query : queries) {
        if (query[0] == 1) {
          int l = query[1];
          int r = query[2];
          int k = query[3];
          if (k >= 5)  {
            res.push_back(0);
          } else {
            res.push_back(tree[k].query(r + 1, l + 1));
          }
        } else if (query[0] == 2) {
          int i = query[1];
          long long val = query[2];
          int newDepth = getDepth(val);
          int oldDepth = getDepth(nums[i]);
          tree[newDepth].update(i+1, 1);
          tree[oldDepth].update(i+1, -1);
          nums[i] = val;
        }
      }
      return res;
    }

    int getDepth(long long x) 
    {
      int count = 0;
      while (x != 1LL) {
        x = __builtin_popcountll(x);
        count++;
      } 
      return count;
    }
};

