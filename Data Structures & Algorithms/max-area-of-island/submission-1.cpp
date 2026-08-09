class Solution {
public:
int dfs(int r,int c,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();

    if(r<0||r>=n||c<0||c>=m||grid[r][c]==0) return 0;
    grid[r][c]=0;
    return 1+dfs(r+1,c,grid)+dfs(r-1,c,grid)+dfs(r,c+1,grid)+dfs(r,c-1,grid);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
 int n=grid.size();
 int m=grid[0].size();
 int ans=0;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]){
            ans=max(ans,dfs(i,j,grid));
        }
    }
 }
 return ans;
     }
};
