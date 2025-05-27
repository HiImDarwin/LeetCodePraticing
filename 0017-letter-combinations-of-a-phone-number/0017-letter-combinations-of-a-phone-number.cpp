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

        letters.push_back(' ');
        for(const int &c : digitMap[digits[index]-'0']) {
            letters[index] = c;
            backtracking(res, digits, index+1, letters);
        }
    }
    const std::vector<std::string> digitMap = {
		"", "", "abc", "def","ghi","jkl", "mno", "pqrs","tuv","wxyz"};
};