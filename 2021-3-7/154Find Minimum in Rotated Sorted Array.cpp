//class Solution {
//public:
//	int findMin(vector<int>& nums) {
//		int low = 0;
//		int high = nums.size() - 1;
//		while (low < high) {
//			int mid = low + (high - low) / 2;
//			if (nums[mid] < nums[high]) {//���midС��high����˵��mid��߶���������У������ų��ұ�
//				high = mid;
//			}
//			else if (nums[mid] > nums[high]) {//���mid����high����˵��midǰ�߶���������У������ų����
//				low = mid + 1;
//			}
//			else {
//				high--;//�����ظ�ֵ�Ĵ�����1 1 1 1 1 1 0 1 1��0 1 1 1 1 1 1 1
//			}
//		}
//		return nums[low];
//	}
//};
//
