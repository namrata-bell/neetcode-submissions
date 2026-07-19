class Solution {
public:
    int nextNumber(int n) {

        int sum = 0;

        while (n) {

            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
//vvimp
    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        do {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        } while (slow != fast);

        return slow == 1;
    }
};