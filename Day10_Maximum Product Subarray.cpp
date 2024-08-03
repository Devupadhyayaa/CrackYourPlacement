class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long pre=0,suf=0,ans = nums[0];
        for(int i=0;i<nums.size();i++){
            if(pre==0||pre*nums[i]<INT_MIN)
                pre=nums[i];
            else
                pre*=nums[i];
            if(suf==0||suf*nums[nums.size()-i-1]<INT_MIN)
                suf=nums[nums.size()-i-1];
            else
                suf*=nums[nums.size()-i-1];
            ans = max({ans,pre,suf});
        }
        return ans;
    }
};
