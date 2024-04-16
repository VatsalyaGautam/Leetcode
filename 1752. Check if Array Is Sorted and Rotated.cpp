class Solution {
public:
    bool check(vector<int>& nums) {
    int n = nums.size();
    int cnt=0;
    for(int i =0;i<n-1;i++)
    {
        if(nums[i]>nums[i+1]){
            cnt++;
        }

    }
    if(nums[n-1]> nums[0])
    {
        cnt++;
    }
    return cnt<=1;
    }
};
