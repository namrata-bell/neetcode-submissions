//see again
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;

    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void dfs(string &s, int start) {

        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (isPalindrome(s, start, end)) {

                curr.push_back(s.substr(start, end - start + 1));

                dfs(s, end + 1);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        dfs(s, 0);

        return ans;
    }
};