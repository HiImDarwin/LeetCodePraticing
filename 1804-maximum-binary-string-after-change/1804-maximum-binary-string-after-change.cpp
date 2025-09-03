class Solution {
public:
    string maximumBinaryString(string binary) {
      int n = binary.length();
      int curr = 0, prev = -1;
      while (curr < n) {
        if (binary[curr] == '0' && prev == -1) {
          prev = curr;
        } else if (binary[curr] == '0') {
          binary[curr] = '1';
          binary[prev] = '1';
          binary[prev+1] = '0';
          prev++;
        }
        curr++;
      }
      return binary;
    }
};

/*
00 -> 10
010 -> 101
0110 -> 1011
01110 -> 10111
01111
when met 0 keep goint find next 0
turn that 0 to 1
turn prev 0 to 1 and next to 0

*/