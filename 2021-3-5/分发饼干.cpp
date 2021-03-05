//#include<iostream>
//#include<vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int findContentChildren(vector<int>& g, vector<int>& s) {
//		sort(g.begin(), g.end());
//		sort(s.begin(), s.end());
//		int numOfChildren = g.size(), numOfCookies = s.size();
//		int count = 0;
//		for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
//			while (j < numOfCookies && g[i] > s[j]) {
//				j++;
//			}
//			if (j < numOfCookies) {
//				count++;
//			}
//		}
//		return count;
//	}
//	//int findContentChildren(vector<int>& g, vector<int>& s) {
//	//	sort(g.begin(), g.end());
//	//	sort(s.begin(), s.end());
//	//	int count = 0;
//	//	for (int i = 0,j = 0; i < g.size() && j < s.size(); i++, j++) {
//	//		while (g[i] > s[j] && j != s.size()) {
//	//			j++;
//	//		}
//	//		if (j < s.size()) {
//	//			count++;
//	//		}
//	//	}
//	//	return count;
//	//}
//	
//};
//
//int main() {
//	Solution solution;
//	vector<int> g{ 10, 9, 8, 7 };
//	vector<int> s{ 5, 6, 7, 8 };
//
//	cout <<solution.findContentChildren(g,s);
//
//	/*vector<int> test{ 5,3,1,2 };
//	sort(test.begin(), test.end());
//	for (auto i = test.begin(); i != test.end(); i++)
//	{
//		cout << *i;
//	}
//	for (int i = 0; i != test.size(); i++) {
//		cout << test[i];
//	}*/
//	return 0;
//}
//
////class Solution {
////public:
////	int findContentChildren(vector<int>& g, vector<int>& s) {
////		sort(g.begin(), g.end());
////		sort(s.begin(), s.end());
////		int a = g.size();
////		int b = s.size();
////		int count = 0;
////		for (int i = 0, j = 0; i < a && j < b; i++, j++) {
////			while (g[i] > s[j] && j < b) {
////				j++;
////			}
////			if (j < b) {
////				count++;
////			}
////		}
////		return count;
////	}
////};