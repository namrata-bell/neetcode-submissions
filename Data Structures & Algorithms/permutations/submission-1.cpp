class Solution {
public:
vector<int>path;
vector<vector<int>>res;
vector<bool>used;
void back(vector<int>&nums){
    if(path.size()==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i])continue;
        used[i]=true;
        path.push_back(nums[i]);
        back(nums);
        path.pop_back();
        used[i]=false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(),false);
        back(nums);
        return res;
    }
};
