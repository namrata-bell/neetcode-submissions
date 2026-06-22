class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
//         brute force tc= nearly cube
//         class Solution {
// public:
//     void markRow(vector<vector<int>>& matrix, int n, int m, int i) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = -1;
//             }
//         }
//     }

//     void markCol(vector<vector<int>>& matrix, int n, int m, int j) {
//         for (int i = 0; i < n; i++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = -1;
//             }
//         }
//     }

//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         // Mark rows and columns
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     markRow(matrix, n, m, i);
//                     markCol(matrix, n, m, j);
//                 }
//             }
//         }

//         // Convert all -1 to 0
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == -1) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };



//better tc=O(2*n*m) sc=O(n)+O(m)
int m=matrix.size();
int n=matrix[0].size();
vector<int> col(n,0);
vector<int> row(m,0);
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==0){
            row[i]=1;
            col[j]=1;
        }
    }
}

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(row[i]||col[j]){
            matrix[i][j]=0;
        }
    }
}

// optimal can only optimise space and lengthy
    }
};
