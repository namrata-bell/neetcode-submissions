class Solution {
public:
//sc=O(1)//tc=O(n^2)
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//brute force with same tc but extra space of O(n^2)
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();

//         vector<vector<int>> ans(n, vector<int>(n));

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 ans[j][n - 1 - i] = matrix[i][j];
//             }
//         }

//         matrix = ans;
//     }
// };
