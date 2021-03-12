class Solution {//爬楼梯第i阶的方法等于第i-1阶加i-2阶，利用斐波那契数列完成
public:
	int climbStairs(int n) {
		if (n <= 2) { return n; }
		vector<int> dp(n + 1, 1);
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};
//由于只需要输出第i层，故优化空间复杂度
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) { return n; }
		int pre2 = 1, pre1 = 2, cur;
		for (int i = 2; i < n; i++) {
			cur = pre1 + pre2;
			pre2 = pre1;
			pre1 = cur;
		}
		return cur;
	}
};
