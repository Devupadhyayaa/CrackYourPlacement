  #define ull unsigned long long
  public:
    string a,b;
    ull gethash(const vector<ull>&Prefix,int size,int K,int M,const vector<ull>&X){
        return Prefix[K] - Prefix[M]*X[size];
    }
    bool chk(int n,int m,int mid, const vector<ull>&P1, const vector<ull>&P2,const vector<ull>&X){
        unordered_map<ull,int>um;
        for(int i=0;i<=n-mid;i++){
            ull idx = gethash(P1,mid,mid+i,i,X);
            um[idx]++;
        }
        for(int i=0;i<=m-mid;i++){
            ull idx = gethash(P2,mid,mid+i,i,X);
            if(um.count(idx))return true;
        }
        return false;
    }
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int x = 123LL;
        int n=s1.size();
        int m=s2.size();
        a=s1;
        b=s2;
        vector<ull>P1(n+1),P2(m+1),X(max(m,n)+1,1);
        for(int i=1;i<=n;i++) P1[i]=((P1[i-1]*x) + s1[i-1]);
        for(int i=1;i<=m;i++) P2[i]=((P2[i-1]*x) + s2[i-1]);
        for(int i=1;i<=max(n,m);i++) X[i]=(X[i-1]*x);

        int l=1, h = min(m,n), ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(chk(n,m,mid,P1,P2,X)){
                ans=max(mid,ans);
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};
