class Solution {
public:
    void dfs(vector<vector<char>>&arr,int i, int j){
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(auto dir : directions){
            int di = i + dir.first;
            int dj = j + dir.second;
            if(di>=0&&di<arr.size()&&dj>=0&&dj<arr[0].size()&&arr[di][dj]=='1'){
                arr[di][dj]='2';
                dfs(arr,di,dj);
            }
        }
    }
    int numIslands(vector<vector<char>>& arr) {
        int ans =0;
        for(int i =0;i<arr.size();i++){
            for(int j = 0;j<arr[0].size();j++){
                if(arr[i][j]=='1'){
                    ans++;
                    arr[i][j]='2';
                    dfs(arr,i,j);
                }
            }
        }
        return ans;
    }
};
