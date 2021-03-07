//class Solution {
//public:
//	bool search(vector<int>& nums, int target) {
//		int start = 0, end = nums.size() - 1;
//		while (start <= end) {
//			int mid = start + (end - start) / 2;
//			if (nums[mid] == target) { return true; }
//			if (nums[start] == nums[mid]) { start++; }//考虑特殊情况如[1,1,1,1,1,1,2,1,1]
//			//对于一般情况，数组旋转后是一个先降后升的折线，通过判断mid在折点左边还是右边，有不同的情况。
//			else if (nums[mid] > nums[end]) {//如果mid大于high，则说明mid前边都是升序队列
//				if (nums[mid] > target&& nums[start] <= target) {//判断target是否在mid和start之间
//					end = mid - 1;
//				}
//				else {//target在MID之后
//					start = mid + 1;
//				}
//			}
//			else {
//				if (nums[mid] < target && nums[end] >= target) {//如果mid小于high，则说明mid后边都是升序队列
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
