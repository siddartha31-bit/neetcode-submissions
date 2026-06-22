class Solution {
public:
    vector<string> result;
    string phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int i, string current) {
        if (i == digits.size()) {
            result.push_back(current);
            return;
        }
        for (char c : phone[digits[i] - '0'])
            backtrack(digits, i + 1, current + c);
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack(digits, 0, "");
        return result;
    }
};