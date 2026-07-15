class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int target) {

        if (left == right)
            return nums[left];

        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == target)
            return nums[pivotIndex];

        if (pivotIndex < target)
            return quickSelect(nums, pivotIndex + 1, right, target);

        return quickSelect(nums, left, pivotIndex - 1, target);
    }

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};


//min heap
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {

//         priority_queue<int, vector<int>, greater<int>> pq;

//         for (int num : nums) {
//             pq.push(num);

//             if (pq.size() > k)
//                 pq.pop();
//         }

//         return pq.top();
//     }
// };