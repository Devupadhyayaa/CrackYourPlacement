class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[res]==nums[i])count++;
            else count--;
            if(count==0){res=i;count=1;}
        }
        count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[res]==nums[i])count++;
        }
        if(count>nums.size()/2)
            return nums[res];
        return -1;
    }
};
