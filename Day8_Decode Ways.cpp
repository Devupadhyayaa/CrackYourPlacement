class Solution {
public:
    int dp[101][2];
    int solve(string&s, int idx,int x){

        if(idx==s.size()){
            if(x==1)return 0;
            return 1;
        }
        if(dp[idx][x]!=-1)return dp[idx][x];
        if(x==0&&s[idx]=='0') return dp[idx][x]=0;

        int tak1=0,tak2=0;
        if(x==1){
            if((s[idx-1]-'0')*10+(s[idx]-'0')>26) return dp[idx][x]=0;
            return tak1 = solve(s,idx+1,0);
        }
        else{
            tak1 = solve(s,idx+1,0);
            tak2 = solve(s,idx+1,1);
        }

        return dp[idx][x] = tak1+tak2;
    }
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};
