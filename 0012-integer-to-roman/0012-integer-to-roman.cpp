class Solution {
public:
    string intToRoman(int num) {
      string res;
      int digit = 0;
      while(num >0) {
        int dec = num%10;
        res = changeToRoam(dec,digit) + res;
        num = num / 10;
        digit++;
      }
      return res;
    }

    string changeToRoam(int num, int digit) {
      if(digit == 3) {
        return string(num, 'M');
      }
      string one = table[digit][0];
      string five = table[digit][1];
      string ten = table[digit+1][0];
      
      if(num == 9) return one+ten;
      if(num >= 5) return five + string(num-5,one[0]);
      if(num == 4) return one + five;
      return string(num, one[0]);
    }

    vector<vector<string>> table = {{"I","V"},{"X","L"},{"C","D"},{"M"}};
};