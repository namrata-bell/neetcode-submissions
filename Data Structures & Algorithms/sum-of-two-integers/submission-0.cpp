class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned carry=(unsigned)(a&b);
            a=a^b;//xor(addition without carry)
            b=carry<<1;

        }
        return a;
    }
};
