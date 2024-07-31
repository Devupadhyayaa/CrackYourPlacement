class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        if(edges.size()<n-1)return -1;
        vector<vector<int>>adj(n);
        vector<int>vis(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                comp++;
                queue<int>q;
                q.push(i);vis[i]++;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            vis[it]++;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return comp-1;
    }
};
