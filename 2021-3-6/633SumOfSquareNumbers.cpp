//暴力法：
class Solution {
public:
	bool judgeSquareSum(int c) {
		for (long a = 0; a * a <= c; a++) {
			double b = sqrt(c - a * a);
			if (b == (int)b) return true;
		}
		return false;
	}
};
//费马平方和定理：一个非负整数C能够表示为两个整数的平方和，当且仅当C的所有形如4k+3的质因子的幂次均为偶数。

public class Solution {
	public boolean judgeSquareSum(int c) {
		for (int i = 2; i * i <= c; i++) {
			int count = 0;
			if (c % i == 0) {
				while (c % i == 0) {
					count++;
					c /= i;
				}
				if (i % 4 == 3 && count % 2 != 0)
					return false;
			}
		}
		return c % 4 != 3;
	}
}
