//ţ�ٵ�������X(n+1)=Xn - f(x)/f'(x)

//class Solution {
//public:
//	int mySqrt(int a) {
//		long x = a;
//		while (x * x > a) {
//			x = (x + a / x) / 2;
//		}
//		return x;
//	}
//};

//���߷��� ע��������ͷ�ֹ��ʧС�� X(n+1)=Xn - f(x) (Xn-X(n-1))/f(Xn)-f(X(n-1))
//class Solution {
//public:
//	int mySqrt(int a) {
//		double x = a;
//		double y = a - 1;
//		while (x * x > a) {
//			double temp = x;
//			int z = x - (x * x - a) * ((x - y) / (x * x - y * y));
//			x = z;
//			y = temp;
//		}
//		return x;
//	}
//};

//���ַ�:
//class Solution {
//public:
//	int mySqrt(int x) {
//		int start = 0;
//		int end = x;
//		int ans;
//		while (start <= end) {
//			int mid = start + (end - start) / 2;
//			if ((long long)mid * mid <= x) {
//				ans = mid;
//				start = mid + 1;
//			}
//			else {
//				end = mid - 1;
//			}
//		}
//		return ans;
//	}
//};