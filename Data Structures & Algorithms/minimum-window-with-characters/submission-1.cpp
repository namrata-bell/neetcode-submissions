class Solution {
public:
//vvimp
    string minWindow(string s, string t) {

        unordered_map<char, int> target, window;

        for (char c : t)
            target[c]++;

        int have = 0;
        int need = target.size();

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            if (target.count(c) && window[c] == target[c])
                have++;

            while (have == need) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                window[ch]--;

                if (target.count(ch) && window[ch] < target[ch])
                    have--;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};