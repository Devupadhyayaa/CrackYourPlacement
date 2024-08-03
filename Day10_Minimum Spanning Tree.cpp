    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<int>vis(n);
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            int node = it.second;
            int wt = it.first;
            if(vis[node]==1)continue;
            vis[node]=1;
            ans+=wt;
            for(auto el : adj[node]){
                int ed = el[0]; int edwt = el[1];
                if(!vis[ed])pq.push({edwt,ed});
            }
        }
        return ans;
    }
