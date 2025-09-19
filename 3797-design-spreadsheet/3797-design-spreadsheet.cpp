class Spreadsheet {
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
      sheet.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
      int y = cell[0] - 'A';
      int x = stoi(cell.substr(1)) - 1;
      sheet[x][y] = value;
    }
    
    void resetCell(string cell) {
      setCell(cell, 0);
    }
    
    int getValue(string formula) {
      vector<int> nums;
      int tmp = 0;
      int sign = 1;
      for (int i = 1; i < formula.length(); i++) {  
        if (formula[i] == '+') {
          nums.push_back(tmp * sign);
          sign = 1;
        } else if (formula[i] == '-') {
          nums.push_back(tmp * sign);
          sign = -1;
        } else if (isalpha(formula[i])) {
          int y = formula[i] - 'A';
          i++;
          int x = 0;
          while (i < formula.length() && isdigit(formula[i])) {
            x *= 10;
            x += formula[i] - '0';
            i++;
          }
          x--;
          nums.push_back(sheet[x][y] * sign);
        } else {
          int num = 0;
          while (i < formula.length() && isdigit(formula[i])) {
            num *= 10;
            num += formula[i] - '0';
            i++;
          }
          nums.push_back(num * sign);
        }
      }
      int res = 0;
      for(auto& num : nums) {
        res += num;
      }
      return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */