class Solution {
public:
    // int compareVersion(string version1, string version2) {
    //   int ver1, ver2;
    //   int l = 0, r = 0;
    //   while (l < version1.length() && r < version2.length()) {
    //     ver1 = 0;
    //     ver2 = 0;
        
    //     while (l < version1.length() && version1[l] != '.' ) {
    //       ver1 *= 10;
    //       ver1 += version1[l] - '0';
    //       l++;
    //     }

    //     while (r < version2.length() && version2[r] != '.' ) {
    //       ver2 *= 10;
    //       ver2 += version2[r] - '0';
    //       r++;
    //     }

    //     if (ver1 < ver2) {
    //       return -1;
    //     } else if (ver1 > ver2) {
    //       return 1;
    //     }

    //     l++;
    //     r++;
    //   }
    //   if (l < version1.length() && checkRemaining(l, version1)) {
    //     return 1;
    //   } else if (r < version2.length() && checkRemaining(r, version2)) {
    //     return -1;
    //   }

    //   return 0;
    // }


    // bool checkRemaining(int idx, string& version) {
    //   while (idx < version.length()) {
    //     if (version[idx] != '.' && version[idx] != '0') {
    //       return true; // 有非 0 的數字
    //     }
    //     idx++;
    //   }
    //   return false;
    // }

    int compareVersion(string version1, string version2) {
      stringstream s1(version1), s2(version2);
      string token1, token2;

      while (s1.good() || s2.good()) {
        getline(s1, token1, '.');
        getline(s2, token2, '.');
        int num1 = token1.empty() ? 0 : stoi(token1);
        int num2 = token2.empty() ? 0 : stoi(token2);
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        token1.clear();
        token2.clear();
      }
      return 0;
    }
};

/*
compare each part of revisions



*/