class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(vector<int>& candidates, int target, int start) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, no need to continue
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // Use next index because each element is used once
            dfs(candidates, target - candidates[i], i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0);

        return ans;
    }
};