class Solution {
public:
    int x = 20;
    vector<int>dp;
    Solution() : x(20), dp(x, -1) {}
    int numTrees(int n) {
        if(n <= 1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return dp[n]=ans;
    }
};
