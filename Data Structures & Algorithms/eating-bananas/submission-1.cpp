class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int hi=*max_element(piles.begin(),piles.end());
        
        while(l<=hi){
           int k=l+(hi-l)/2;
            long long hours=0;

            for(int pile:piles){
                hours+=(pile+k-1)/k;
            }
            if(hours<=h){
                hi=k-1;
            }
            else l=k+1;
        }
        return l;
    }
};
