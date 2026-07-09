class Solution {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {

        string res;

        for (string s : strs) {
            res += to_string(s.size()) + "#" + s;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {

        vector<string> ans;
        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#')
                j++;

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Move to first character
            j++;

            ans.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return ans;
    }
};