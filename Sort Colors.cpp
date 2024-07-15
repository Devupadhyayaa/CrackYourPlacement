class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        for(auto it:nums){
            if(it==0)z++;
            else if(it==1)o++;
            else t++;
        }
        for(int i=0;i<z;i++)nums[i]=0;
        for(int i=z;i<z+o;i++)nums[i]=1;
        for(int i=z+o;i<nums.size();i++)nums[i]=2;
    }
};
