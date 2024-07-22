int missingNumber(int arr[], int n) 
    { 
        // Your code here
        unordered_map<int,int>mp;
        int x = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                mp[arr[i]]++;
                x=min(x,arr[i]);
            }
            mx=max(mx,arr[i]);
        }
        if(x!=1)return 1;
        for(int i=x;i<1e6;i++){
            if(!mp.count(i))return i;
        }
        
        return mx+1;
    } 
