class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(char c:s){
            if(isalnum(c)){
                t+=tolower(c);
            }
        }
        int n=t.size();
        for(int i=0;i<(t.size())/2;i++){
            if(t[i]!=t[n-i-1]) return false;
        }
        return true;
    }
};
