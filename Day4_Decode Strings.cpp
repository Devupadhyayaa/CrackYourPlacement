class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                string temp = "";
                
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                
                string val = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    val = st.top() + val;
                    st.pop();
                }
                int k = stoi(val);
    
                string ans = "";
                for (int j = 0; j < k; j++) {
                    ans += temp;
                }
                st.push(ans);
            }
            else {
                st.push(string(1, s[i]));
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
