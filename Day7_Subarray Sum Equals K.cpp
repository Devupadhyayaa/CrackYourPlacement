class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int>prefix(n);prefix[0]=nums[0];
        unordered_map<int,int>mp;
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        for(int i=0;i<n;i++){
            if(prefix[i]==k)ans++;
            if(mp.count(prefix[i]-k))ans+=mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        return ans;
    }
};
