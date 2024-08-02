class Solution {
private:
    bool dfs(vector<int>adj[],vector<int>&vis,int node,int parent){
        if(parent==-1)vis[node]=0;
        else vis[node]=parent^1;
        bool ans=true;
        for(auto it:adj[node]){
            if(vis[it]==-1){
                ans=ans&dfs(adj,vis,it,vis[node]);
            }
            else if(vis[it]==vis[node]){
                return false;
            }
        }
        return ans;
    }
public:
	bool isBipartite(int n, vector<int>adj[]){
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(adj,vis,i,-1)){
                    return false;
                }
            }
        }
        return true;
    }
};
