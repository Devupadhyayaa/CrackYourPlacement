int mctFromLeafValues(vector<int>& A) {
    int r = 0;
    vector<int> s = {INT_MAX};
    for (int a : A) {
        while (s.back() <= a) {
            int m = s.back(); s.pop_back();
            r += m * min(s.back(), a);
        }
        s.push_back(a);
    }
    for (int i = 2; i < s.size(); ++i) {
        r += s[i] * s[i - 1];
    }
    return r;
}
