class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int h, int target) {
        if (l > h) return -1;

        int m = l + (h - l) / 2;

        if (nums[m] == target)
            return m;
        else if (target < nums[m])
            return binarySearch(nums, l, m - 1, target);
        else
            return binarySearch(nums, m + 1, h, target);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};