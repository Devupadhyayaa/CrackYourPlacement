    int dp[501][2005];
    int solve(vector<int>&nums,int k,int idx,int rem){
        if(idx==nums.size()) return 0;
        
        if(dp[idx][rem+1]!=-1)return dp[idx][rem+1];
        int ans;
        if(rem-nums[idx]<0){
           ans = ((rem+1)*(rem+1))+solve(nums,k,idx,k);
        }
        else{
            if(rem==k){
                ans = solve(nums,k,idx+1,rem-(nums[idx]+1));
            }
            else{
                int val1 = ((rem+1)*(rem+1))+solve(nums,k,idx,k);
                int val2 = solve(nums,k,idx+1,rem-(nums[idx]+1));
                ans = min(val1,val2);
            }
        }
        return dp[idx][rem+1] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp,-1,sizeof(dp));
        return solve(nums,k,0,k);
    }
