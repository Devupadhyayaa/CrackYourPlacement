class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0,h = nums.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(mid-1>=0&&mid+1<nums.size()&&nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid+1<nums.size()&&nums[mid]<nums[mid+1]){
                l = mid+1;
            }
            else h = mid-1;
        }
        return l;
    }
};
