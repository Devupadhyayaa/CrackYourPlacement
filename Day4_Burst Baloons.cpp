class Solution {
public:
    int dp[500][500];
    int solve(vector<int>&nums,int i,int j){
        if(i+1==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        for(int idx = i+1;idx<j;idx++){
            int val = nums[i]*nums[idx]*nums[j] + solve(nums,i,idx) + solve(nums,idx,j);
            ans = max(val,ans);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int sz = nums.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,sz);
    }
};
