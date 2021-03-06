//��������
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
//����ƽ���Ͷ���һ���Ǹ�����C�ܹ���ʾΪ����������ƽ���ͣ����ҽ���C����������4k+3�������ӵ��ݴξ�Ϊż����

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
