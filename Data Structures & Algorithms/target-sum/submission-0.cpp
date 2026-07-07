class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //s1-s2=target
        int tots=accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>tots) return 0;
        if((tots+target)%2!=0) return 0;
        int s1=(tots+target)/2;
        vector<int>dp(s1+1,0);
        dp[0]=1;
        for(int num:nums){
            for(int j=s1;j>=num;j--){
                dp[j]+=dp[j-num];
            }
        }

return dp[s1];
    }
};
