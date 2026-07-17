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
//     Interview takeaway
// a ^ b → adds bits without carry.
// a & b → finds the carry bits.
// carry << 1 → moves the carry to the next higher bit.
// Repeat until there is no carry left.
};
