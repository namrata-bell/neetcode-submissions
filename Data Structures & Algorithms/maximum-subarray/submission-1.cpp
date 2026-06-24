class Solution {
public:
    int maxSubArray(vector<int>& nums) {
int maxs=nums[0];
int currs=nums[0];
for(int i=1;i<nums.size();i++){
    currs=max(nums[i],currs+nums[i]);
    maxs=max(maxs,currs);}
return maxs;

    }
};
