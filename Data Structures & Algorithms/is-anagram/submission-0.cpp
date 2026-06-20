class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]!=0) return false;
        }
        return true;
    }
};
