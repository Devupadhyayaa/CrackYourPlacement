    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(2501,1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        int mx=0;
        for(auto it:dp)mx=max(it,mx);
        return mx;
    }
