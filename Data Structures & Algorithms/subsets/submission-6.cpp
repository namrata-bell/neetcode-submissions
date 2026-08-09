class Solution {
public:
vector<vector<int>>ans;
vector<int>subset;
void back(vector<int>&nums,int index){
    if(index==nums.size()){
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[index]);
    back(nums,index+1);
    subset.pop_back();
    back(nums,index+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
    back(nums,0);
    return ans;
    }
};