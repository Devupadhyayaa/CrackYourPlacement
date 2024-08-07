class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        unordered_map<char,int>um;
        um[')']=0,um['}']=1,um[']']=2;
        for(auto ch : s){
            if(ch == '(')st.push(0);
            else if(ch == '{')st.push(1);
            else if(ch == '[')st.push(2);
            else {
                if (st.empty() || st.top() != um[ch]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
