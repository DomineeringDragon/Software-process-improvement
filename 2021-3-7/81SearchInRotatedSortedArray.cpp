//class Solution {
//public:
//	bool search(vector<int>& nums, int target) {
//		int start = 0, end = nums.size() - 1;
//		while (start <= end) {
//			int mid = start + (end - start) / 2;
//			if (nums[mid] == target) { return true; }
//			if (nums[start] == nums[mid]) { start++; }//�������������[1,1,1,1,1,1,2,1,1]
//			//����һ�������������ת����һ���Ƚ����������ߣ�ͨ���ж�mid���۵���߻����ұߣ��в�ͬ�������
//			else if (nums[mid] > nums[end]) {//���mid����high����˵��midǰ�߶����������
//				if (nums[mid] > target&& nums[start] <= target) {//�ж�target�Ƿ���mid��start֮��
//					end = mid - 1;
//				}
//				else {//target��MID֮��
//					start = mid + 1;
//				}
//			}
//			else {
//				if (nums[mid] < target && nums[end] >= target) {//���midС��high����˵��mid��߶����������
//					start = mid + 1;
//				}
//				else {
//					end = mid - 1;
//				}
//			}
//		}
//		return false;
//	}
//};
