class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int n=nums.size();
        if(nums[0]>nums[1]) return 0;
        if(nums[n-2]<nums[n-1]) return n-1;
        int l=1;
        int h=n-2;
        int m;
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]>nums[m+1]&& nums[m]>nums[m-1]){
                return m;
            }
            else if(nums[m]>nums[m+1]){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return -1;
     }
};