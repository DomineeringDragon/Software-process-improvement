//class Solution {
//public:
//	int findMin(vector<int>& nums) {
//		int low = 0;
//		int high = nums.size() - 1;
//		while (low < high) {
//			int mid = low + (high - low) / 2;
//			if (nums[mid] < nums[high]) {//如果mid小于high，则说明mid后边都是升序队列，可以排除右边
//				high = mid;
//			}
//			else if (nums[mid] > nums[high]) {//如果mid大于high，则说明mid前边都是升序队列，可以排除左边
//				low = mid + 1;
//			}
//			else {
//				high--;//考虑重复值的存在如1 1 1 1 1 1 0 1 1和0 1 1 1 1 1 1 1
//			}
//		}
//		return nums[low];
//	}
//};
//
