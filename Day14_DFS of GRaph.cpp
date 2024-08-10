class Solution {
  private:
    
    void dfs(vector<int>adj[],int node,vector<int>&vis,vector<int>&ans){
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,it,vis,ans);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int>vis(v);
        vector<int>ans;
        dfs(adj,0,vis,ans);
        return ans;
    }
};
