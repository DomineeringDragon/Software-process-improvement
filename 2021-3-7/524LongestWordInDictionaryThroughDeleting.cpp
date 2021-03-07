//class Solution {
//public:
//	// bool mycompare(string a,string b){
//	//     return
//	// }
//	string findLongestWord(string s, vector<string>& d) {
//		sort(
//			d.begin(),
//			d.end(),
//			greater<string>());
//		int lengths = s.size();
//		for (int num = 0; num < d.size(); num++) {
//			int j = 0;
//			int lengthd = d[num].size();
//			for (int i = 0; i < lengths && j < lengthd; i++) {
//				if (s[i] == d[num][j]) { j++; }
//			}
//			if (j == lengthd) {
//				return d[num];
//			}
//		}
//		return "";
//	}
//};
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//int main() {
//	/*vector<string> d{ "a","b","c" };
//	vector<string>::iterator i;
//	for (i = d.begin(); i != d.end(); i++) {
//		cout << *i << " ";
//	}
//	sort(d.begin(), d.end(), 
//		[](string a,string b)  {
//		if (a.length() == b.length()) {
//			return (bool)b.compare(a);
//		}
//		else {
//			return a.length() > b.length();
//		}
//		});
//	cout<<endl;
//	for (i = d.begin(); i != d.end(); i++) {
//		cout << *i << " ";
//	}*/
//	string a = "ab", b = "ba", c = "a", d = "b",e="a";
//	cout << a.compare(b) << " " << b.compare(a) << " " << c.compare(b) << " " << c.compare(e);
//	cout << endl;
//	
//	return 0;
//
//}