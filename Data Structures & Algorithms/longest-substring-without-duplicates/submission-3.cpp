class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        unordered_set<char>st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            while(st.count(s[i])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
