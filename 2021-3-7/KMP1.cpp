//#include<iostream>
//#include <vector>
//
//using namespace std;
//
//void makeNext(string s, vector<int> next)
//{
//	int len = (int)s.length();
//	next[0] = 0;                    //初始化
//	for (int i = 1, k = 0; i < len; i++)
//	{
//		while (k > 0 && s[k] != s[i])  //这个while是最关键的部分
//			k = next[k - 1];
//		//等价于  k=next[next[i-1]-1]
//		//等号右边的k起的只是下标的作用
//		if (s[k] == s[i])
//			k++;                  //相等就+1
//		next[i] = k;                //赋值
//	}
//}
//	int kmp(string t, string s)
//	{
//		int len1 =(int) t.length();
//		int len2 =(int) s.length();
//		
//		vector<int> next(len2);
//		makeNext(s, next);
//		for (int i = 0, j = 0; i < len1; i++)
//		{
//			while (j > 0 && t[i] != s[j])
//			{
//				j = next[j - 1];
//			}
//			if (t[i] == s[j])
//				j++;
//			if (j == len2)
//				return i - j + 1;
//		}
//	}
//
//	int main()
//	{
//		string t = "1234561123458412";
//		string s= "611";
//		cout << t << endl;
//		cout << s << endl;
//		cout << "下标为" << kmp(t, s) << endl;
//	
//	}
