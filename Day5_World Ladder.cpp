class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wordlist) {
        set<string>st;
        for(int i=0;i<wordlist.size();i++){
            st.insert(wordlist[i]);
        }
        queue<pair<string,int>>q;
        q.push({bw,1});
        int ans=1;
        int chk=0;
        if(st.count(bw)){
            st.erase(bw);
        }
        while(!q.empty()){
            string str=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(str==ew){
                chk=1;
                ans=dis;
                break;
            }
            for(int i=0;i<str.size();i++){
                string temp=str;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(st.count(temp)){
                        q.push({temp,dis+1});
                        st.erase(temp);
                    }
                }
            }
        }
        if(chk)return ans;
        return 0;
    }
};
