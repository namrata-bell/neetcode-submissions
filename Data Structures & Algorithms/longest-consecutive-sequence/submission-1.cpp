class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute for tc=(O(n^2))..sc=O(1)
        // longest =1;
        // for(i=0;i<n;i++){
        //     x=arr[i];
        //     cnt=1;
        //     while(linearsearch(arr,x+1)==true){
        //         x=x+1;
        //         cnt++;
        //     }
        // }

        //better..first sort it
         if(nums.size() == 0) return 0;

    // sort(nums.begin(), nums.end());

    // int n = nums.size();
    // int lastSmaller = INT_MIN;
    // int cnt = 0;
    // int longest = 1;

    // for(int i = 0; i < n; i++) {

    //     if(nums[i] - 1 == lastSmaller) {
    //         cnt += 1;
    //         lastSmaller = nums[i];
    //     }
    //     else if(lastSmaller != nums[i]) {
    //         cnt = 1;
    //         lastSmaller = nums[i];
    //     }

    //     longest = max(longest, cnt);
    // }

    // return longest;

    //optimal(nly under some constraints) 
   set<int>st(nums.begin(),nums.end());
   int longe=1;
   int cnt=1;
   auto prev=st.begin();
   auto it=next(st.begin());
   while(it!=st.end()){
if(*it-*prev==1) cnt++;
else cnt=1;
longe=max(longe,cnt);
prev=it;
++it;
   }
   return longe;
    }
};
