class Solution {
public:
int findm(vector<int>&piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}

int calcTotalHours(vector<int>& piles, int h){
    int tot=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        tot+=ceil((double)piles[i]/(double)h);
    }
    return tot;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,hi=findm(piles);
        while(l<=hi){
            int m=l+(hi-l)/2;
            int tot=calcTotalHours(piles,m);
            if(tot<=h){
                hi=m-1;
            }
            else{
l=m+1;
            }
        }
        return l;
    }
};
