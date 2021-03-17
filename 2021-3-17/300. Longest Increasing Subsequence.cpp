class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_length;
        int n=nums.size();
        if(n<=1)return n;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);//简单分析可知，如果nums i>nums j，那么dp[i]会继承dp[j],并在这基础上加1
                }
            }
            max_length=max(dp[i],max_length);
        }
        return max_length;
    }
};