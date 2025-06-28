// class Solution {
//   int wordLen;
//   int wordNum;
//   int sLen;
// public:
    // vector<int> findSubstring(string s, vector<string>& words) {
    //   sLen = s.length();
    //   wordNum = words.size();
    //   wordLen = words[0].length();

    //   unordered_map<string, int> wordFre;
    //   vector<int> lastSeenPosition(wordNum, INT_MIN);

    //   for(int i = 0; i< wordNum; ++i) {
    //     wordFre[words[i]]++;
    //   }
    //   vector<int> res;
    //   for(int i = 0; i<wordLen ; i++) {
    //     int concatenatedStart =-1;
    //     while (i < sLen-wordLen) {
    //       string word = s.substr(i,wordLen);
    //       if(map.count(word) &&  (lastSeenPosition[map[word]] < concatenatedStart || concatenatedStart == -1)) {
    //         if(concatenatedStart == -1) concatenatedStart = i;
    //         lastSeenPosition[map[word]] = i;
    //         i += wordLen;
    //         if(i - concatenatedStart == wordNum * wordLen) {
    //           res.push_back(concatenatedStart);
    //           concatenatedStart += wordLen;
    //         }
    //       } else if (map.count(word) &&  lastSeenPosition[map[word]] > concatenatedStart) {
    //         concatenatedStart = lastSeenPosition[map[word]] + wordLen;
    //         i += wordLen;
    //       } else {
    //         concatenatedStart = -1;
    //         i++;
    //       }
    //     }
    //   }
    //   return res;
    // }
// };

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty()) return {};
        int wordLen = words[0].size();
        int wordNum = words.size();
        int windowLen = wordLen * wordNum;
        int sLen = s.length();

        unordered_map<string, int> wordFreq;
        for (auto& w : words) wordFreq[w]++;

        vector<int> res;
        for (int offset = 0; offset < wordLen; ++offset) {
            int left = offset, count = 0;
            unordered_map<string, int> windowFreq;

            for (int right = offset; right + wordLen <= sLen; right += wordLen) {
                string word = s.substr(right, wordLen);
                if (wordFreq.count(word)) {
                    windowFreq[word]++;
                    count++;

                    while (windowFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordNum) res.push_back(left);
                } else {
                    windowFreq.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
};

/*

 [a,b,c]

 abcba
 abcxycba
 abbcca 
 
need a structure store last seen position
need two idx for window left and right
if window size = word _num * word_length > find concatenated string

when encounter word not in words or reapeat word in window > not a concatenated string
shift the window start index to next word of repeat word



One corner case is that [foo,ood,oda]
than the string "fooda" will be hard to trace

Qurstion:
will the concatenated string repeat? can i count?
is string build up with same length word?

*/