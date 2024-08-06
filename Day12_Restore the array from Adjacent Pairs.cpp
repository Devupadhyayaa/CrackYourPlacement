class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>&edges) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>vis;
        for(int i =0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            vis[edges[i][0]]=0;
            vis[edges[i][1]]=0;
        }
        int node;
        for(auto it:mp){
            if(it.second.size()==1){
                node = it.first;
                break;
            }
        }
        vector<int>ans;ans.push_back(node);
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            for(auto it:mp[n]){
                if(vis[it]==0){
                    q.push(it);
                    vis[it]=1;
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};
