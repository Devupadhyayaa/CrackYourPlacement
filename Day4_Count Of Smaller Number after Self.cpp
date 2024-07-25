class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            auto it = lower_bound(st.begin(), st.end(), num);
            ans[i] = it - st.begin();
            st.insert(it, num);  
        }

        return ans;
    }
};
