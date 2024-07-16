class Solution {
public:
    int maxProfit(vector<int>& a) {
        int maxp=0;
        int profit=0;
        int n=a.size();
        int val =a[0];
        for(int i=1;i<n;i++){
            if(a[i]>val){
                profit+=(a[i]-val);
                maxp=max(profit,maxp);
                profit=0;
            }
            else {
                val=a[i];
            }
        }
        return maxp;
    }
};
