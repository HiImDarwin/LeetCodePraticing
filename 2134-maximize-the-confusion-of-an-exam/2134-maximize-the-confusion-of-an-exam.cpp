class Solution {
  string answerKey;
  int k;
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
      this->answerKey = answerKey;
      this->k = k;
      return max(countLen('F'), countLen('T'));
    }

    int countLen(char base) {
      int baseCount = 0, opCount = 0;
      int len = 0;
      for (int i = 0, j = 0; i < answerKey.length(); i++) {
        if (answerKey[i] == base) {
          baseCount++;
        } else {
          opCount++;
        }

        while (opCount > k) {
          if (answerKey[j] == base) {
            baseCount--;
          } else {
            opCount--;
          }
          j++;
        }

        len = max(len, i - j + 1);
      }

      return len;
    }
};


/*
matain a sliding window 
T: n F: k


*/