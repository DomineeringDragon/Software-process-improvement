#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>sum, int target) {
		unordered_map<int, int> m;
		for (int i = 0;; i++) {
			unordered_map<int, int>::iterator a = m.find(target - sum[i]);
			if (a!=m.end()) {
				return {a->second,i};
			}
			m[sum[i]] = i;
		}
	}
};

int main() {
	
	Solution solution;
	vector<int> sum{ 2,7,11,15 };
	unordered_map<int, int> t;
	cout << solution.twoSum(sum,9)[0]<< solution.twoSum(sum, 9)[1];
	return 0;
}