class Solution {
public:
    bool ispal(string&s){
        string temp = s;
        reverse(temp.begin(),temp.end());
        return temp == s;
    }
    void solve(vector<vector<string>>&ans,vector<string>&temp,string s){
        if(s==""){ans.push_back(temp);return ;}

        for(int i = 0;i<s.size();i++){
            string x = s.substr(0,i+1);
            if(ispal(x)){
                temp.push_back(x);
                int sz = s.size();
                solve(ans,temp,s.substr(i+1,sz-i+1));
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(ans,temp,s);
        return ans;
    }
};
