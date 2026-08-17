class Solution {
public:
    vector<string> res;
    string path;
    string mp[10] = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int i) {
        if (i == digits.size()) {
            res.push_back(path);
            return;
        }

        string letters = mp[digits[i] - '0'];

        for (int j = 0; j < letters.size(); j++) {
            path += letters[j];
            backtrack(digits, i + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        backtrack(digits, 0);
        return res;
    }
};