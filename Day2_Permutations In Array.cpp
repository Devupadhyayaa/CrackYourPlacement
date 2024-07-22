  #define ll long long
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        multiset<ll>ms;
        for(int i=0;i<n;i++){
            ms.insert(b[i]);
        }
        for(int i=0;i<n;i++){
            ll val = k-a[i];
            auto it = ms.lower_bound(val);
            if(it==ms.end())return false;
            ms.erase(it);
        }
        return true;
    }
