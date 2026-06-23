class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
int x1=0;
        for(int i=1;i<=n;i++){
            x1=x1^i;
        }
        int x2=0;
        for(int i=0;i<n;i++){
            x2=x2^nums[i];
        }
        int miss=x1^x2;
        if(miss>0){
            return miss;
        }
        else 0;
    }
};
