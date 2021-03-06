class Solution {
public:
	bool checknext(string& s, int low, int high) {
		while (low < high) {
			if (s[low] == s[high]) {
				low++;
				high--;
			}
			else return false;
		}
		return true;
	}
	bool validPalindrome(string s) {
		int low = 0, high = s.size() - 1;
		while (low < high) {
			if (s[low] == s[high]) {
				low++;
				high--;
			}
			else {
				return (checknext(s, low + 1, high) || checknext(s, low, high - 1));
			}
		}
		return true;
	}

};