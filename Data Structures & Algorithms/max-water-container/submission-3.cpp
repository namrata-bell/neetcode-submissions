class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int ans=0;
        while(l<r){
            int w=r-l;
int h=min(heights[l],heights[r]);
ans=max(ans,w*h);
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }

        }
        return ans;
    }
};
