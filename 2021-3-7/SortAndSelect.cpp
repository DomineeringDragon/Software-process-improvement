#include<iostream>
#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
void quickSort(vector<int> &v,int l,int r) {//快排一次将以key为准的值，大于它的放在右边，小于他的放在左边
	if (l + 1 >= r) {
		return;
	}
	int first = l, last = r - 1, key = v[first];
	while (first < last) {
		while (first < last && v[last] >= key) {
			--last;
		}
		v[first] = v[last];
		while (first < last && v[first] <= key) {
			++first;
		}
		v[last] = v[first];
	}
	v[first] = key;
	quickSort(v, l, first);
	quickSort(v, first + 1, r);
}

void mergeSort(vector<int> &nums,int l,int r,vector<int> &temp) {
	if (l + 1 >= r) {
		return;
	}
	int mid = l + (r - l) / 2;
	mergeSort(nums, l, mid, temp);
	mergeSort(nums, mid, r, temp);//？

	int p = l, q = mid, i = l;
	while (p < mid || q < r) {
		if (q >= r || (p < mid && nums[p] <= nums[q])) {
			temp[i++] = nums[p++];
		}else {
			temp[i++] = nums[q++];
		}
	}
	for (i = l; i < r; i++) {
		nums[i] = temp[i];
	}
}

void insertSort(vector<int>& nums, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--) {
			swap(nums[j], nums[j - 1]);
		}
	}
}

void bubbleSort(vector<int>& nums, int n) {
	bool swapped;
	for (int i = 1; i < n; i++) {
		swapped = false;
		for (int j = 1; i < n - i + 1; j++) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				swapped = true;
			}
		}
		if (!swapped)break;
	}
}

void selectSort(vector<int>& nums, int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[min]) {
				min = j;
			}
		}
		swap(nums[min], nums[i]);
	}
}

//快速选择
int quickSelection(vector<int>& nums, int l, int r) {
	int i = l + 1, j = r;
	while (true) {
		while (nums[i] <= nums[l] && i < r) {
			i++;
		}
		while (nums[j] >= nums[l] && j > l) {
			j--;
		}
		if (i >= j) {
			break;
		}
		swap(nums[i], nums[j]);
	}
	swap(nums[l], nums[j]);
	return j;
}
int findKthLargest(vector<int>& nums, int k) {
	int l = 0,  r = nums.size() - 1;
	int target = nums.size() - k;

	while (l < r) {
		int mid = quickSelection(nums,l,r);
		if (mid == target) {
			return nums[mid];
		}
		else if (mid > target) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
}

//桶排序
vector<int> topKFrequently(vector<int> nums,int k) {
	unordered_map<int, int> m;
	int maxCount = 0;
	//寻找出现最多的值并建立哈希表
	for (auto& num : nums) {
		maxCount = max(maxCount, ++m[num]);
	}
	vector<vector<int>>buckets(maxCount + 1);
	for (auto& p : m) {
		buckets[p.second].push_back(p.first);
	}
	vector<int>ans;
	for (int i = maxCount; i >= 0 && ans.size() < k; i--) {
		for (const int& num : buckets[i]) {
			ans.push_back(num);
			if (ans.size() == k)break;
		}
	}
	return ans;
}

void dfs(vector<vector<int>>& isConnected, int i, vector<bool> visited) {

	int m = isConnected.size();
	for (int k = 0; k < m; ++k) {
		if (isConnected[i][k] == 1 && !visited[k]) {
			visited[k] = true;
			dfs(isConnected, k, visited);
		}
	}
}
int findCircleNum(vector<vector<int>>& isConnected) {
	int n = isConnected.size();
	vector<bool> visited(n, false);
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(isConnected, i, visited);
			++count;
		}
	}
	return count;
}

int main() {
	vector<vector<int>> m{ {1,1,0},{1,1,0},{0,0,1} };
	cout << findCircleNum(m);
}