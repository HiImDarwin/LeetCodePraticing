class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        if(digits.length() == 0) return res;
        std::string letters;
        backtracking(res, digits, 0, letters);
        return res;
    }

private:
    void backtracking(std::vector<std::string> &res, std::string &digits, int index, std::string letters) {
        if(index == digits.length()) {
            res.push_back(letters);
            return;
        }
        int round;
        char startChar;
        switch (digits[index]) {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
                round = 3;
                startChar = 'a'+ (digits[index]-'2')*3;
                break;
            case '7':
                round = 4;
                startChar = 'p';
                break;
            case '8':
                round = 3;
                startChar = 't';
                break;
            case '9':
                round = 4;
                startChar = 'w';
                break;

        };
        letters.push_back(' ');
        for(int i=0;i<round;i++) {
            letters[index] = startChar+i;
            backtracking(res, digits, index+1, letters);
        }
    }
};