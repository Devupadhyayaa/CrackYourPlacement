int solve(vector<int>&coins, int n, int k) 
{ 
    sort(coins.begin(),coins.end());
    int remove = ceil(1.0*n/(k+1));
    int ans = 0;
    for(int i=0;i<remove;i++){
        ans+=coins[i];
    }
    return ans;
} 
