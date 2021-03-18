//dp[i][j] 表示从数组的 [0,i]下标范围内选取若干个正整数（可以是 0个），是否存在一种选取方案使得被选取的正整数的和等于j
/*对于 i>0i>0 且 j>0j>0 的情况，如何确定 \textit{dp}[i][j]dp[i][j] 的值？需要分别考虑以下两种情况。

如果 j≥nums[i]，则对于当前的数字nums[i]，可以选取也可以不选取，两种情况只要有一个为true，就有dp[i][j]=true。

如果不选取 nums[i]，则dp[i][j]=dp[i−1][j]；
如果选取nums[i]，则dp[i][j]=dp[i−1][j−nums[i]]。
如果j<nums[i]，则在选取的数字的和等于j的情况下无法选取当前的数字nums[i]，因此有dp[i][j]=dp[i−1][j]。
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;
        int target=sum/2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for(int i=0;i<=n;++i){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;++i){
            for(int j=nums[i-1];j<=target;++j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};