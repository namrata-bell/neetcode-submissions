class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int sell=prices[i]-mini;
            pro=max(pro,sell);
            mini=min(mini,prices[i]);
        }
        return pro;
    }

};
