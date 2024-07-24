class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>st;
       int val;
       for(auto ch :tokens){
            if(ch=="+"||ch=="-"||ch=="/"||ch=="*"){
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();
                if(ch=="+") val = val1+val2;
                else if(ch=="-") val = val1-val2;
                else if(ch=="*") val = val1*val2;
                else val = val1/val2;
                st.push(val);
            }
            else st.push(stoi(ch));
       }
       return st.top();
    }
};
