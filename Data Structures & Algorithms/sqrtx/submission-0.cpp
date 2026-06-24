class Solution {
public:
    int mySqrt(int x) {
        int l=1,h=x;
        while(l<=h){
        long long m=l+(h-l)/2;
        long long val=m*m;
        if(val<=x){
            l=m+1;
        }
        else{
            h=m-1;
        }
        }
        return h;
    }
};