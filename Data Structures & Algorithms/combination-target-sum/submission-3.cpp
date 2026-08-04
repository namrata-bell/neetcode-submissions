class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int idx, vector<int>& nums, int target) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == nums.size() || target < 0)
            return;

        // Take current element
        temp.push_back(nums[idx]);
        solve(idx, nums, target - nums[idx]);   // same index (reuse allowed)
        temp.pop_back();

        // Skip current element
        solve(idx + 1, nums, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(0, nums, target);
        return ans;
    }
};