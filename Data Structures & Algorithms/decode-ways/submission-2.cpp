class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int next2 = 1;   // dp[n]
        int next1 = 0;   // dp[n-1]

        if (s[n - 1] != '0')
            next1 = 1;

        for (int i = n - 2; i >= 0; i--) {

            int curr = 0;

            if (s[i] != '0') {

                curr = next1;

                if (s[i] == '1' ||
                   (s[i] == '2' && s[i + 1] <= '6'))
                {
                    curr += next2;
                }
            }

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};