class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      //asked in ituring interview  
      int m=matrix.size();
      int n=matrix[0].size();
      int l=0;
      int h=n*m-1;
      while(l<=h){
        int mid=l+(h-l)/2;
        int r=mid/n;
        int c=mid%n;
        if(matrix[r][c]==target) return true;
        else if(matrix[r][c]<target)l=mid+1;
        else h=mid-1;}
        return false;
      
    }
};
