class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,lft=0,rht=0,val=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=lft)lft=height[l];
                else val+=lft-height[l];
                l++;
            }
            else{
                if(height[r]>=rht)rht=height[r];
                else val+=rht-height[r];
                r--;
            }
        }
        return val;
    }
};
