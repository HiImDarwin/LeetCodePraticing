class Solution {
public:
    string resultingString(string s) {
      vector<char> stack;
      for (char c: s) {
        if (!stack.empty() && (abs(c - stack.back()) == 1 ||abs(c - stack.back()) == 25)) {
          stack.pop_back();
        } else {
          stack.push_back(c);
        }
      }
      return string(stack.begin(), stack.end());
    }
};

/*

(a - b + 26) %26 == 25
(b - a + 26) %26 == 1
(a - z + 26) % 26 == 1
(z - a + 26) % 26 == 25
brute force

O(n) two pointer
XXXXXXXXX
^^
XXX##XX
  ^  ^
XX####XXXXXXX
 ^    ^
XXOOOOXXXXXXX
      ^^
*/