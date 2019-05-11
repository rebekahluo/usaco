#include <bits/stdc++.h>
using namespace std;

int t1, t2;

vector<int> a;
vector<int> b;

int c[2000 + 10];

// 2  -- >  1
void friday(int t1, vector<int> a, vector<int> b)
{
	for (int i = 0; i < b.size(); i++)
	{
		int nai = b[i];
		vector<int> aa = a;
		vector<int> bb = b;
		bb.erase(bb.begin() + i);
		aa.push_back(nai);
		c[t1 + nai] = 1;
	}
}
// 1 -- > 2
void thursday(int t1, vector<int> a, vector<int> b)
{
	for (int i = 0; i < a.size(); i++)
	{
		// 记录第i个桶的奶量 
		int nai = a[i];
		
		// 新建一个数组a和数组b的备份
		vector<int> aa = a;
		vector<int> bb = b;
		
		// 把数组aa中的第i号桶删除
		aa.erase(aa.begin() + i);
		
		// 往数组bb中添加一个桶，其大小为nai
		bb.push_back(nai);
		
		// 操作星期三
		friday(t1 - nai, aa, bb); 
	}
}

// 2 --> 1
void wednsday(int t1, vector<int> a, vector<int> b)
{

	for (int i = 0; i < b.size(); i++)
	{
		int nai = b[i];
		vector<int> aa = a;
		vector<int> bb = b;
		bb.erase(bb.begin() + i);
		aa.push_back(nai);
		thursday(t1 + nai, aa, bb);
	}
}


// 1 --> 2
void tuesday(int t1, vector<int> a, vector<int> b)
{
	//  从左边的10个桶挑选一个 
	for (int i = 0; i < a.size(); i++)
	{
		// 记录第i个桶的奶量 
		int nai = a[i];
		
		// 新建一个数组a和数组b的备份
		vector<int> aa = a;
		vector<int> bb = b;
		
		// 把数组aa中的第i号桶删除
		aa.erase(aa.begin() + i);
		
		// 往数组bb中添加一个桶，其大小为nai
		bb.push_back(nai);
		
		// 操作星期三
		wednsday(t1 - nai, aa, bb); 
	}
}

void monday()
{
	t1 = 1000;
	t2 = 1000;
	
	tuesday(t1, a, b);
}

int main()
{
	int t;
	
	for (int i = 0; i < 10; i++)
	{
		cin >> t;
		a.push_back(t);
	}
	
	for (int i = 0; i < 10; i++)
	{
		cin >> t;
		b.push_back(t);
	}
	
	monday();
	
	int sum = 0;
	for (int i = 0; i <= 2000; i++)
	{
		sum += c[i];
	}
	cout << sum << endl;
	
	return 0;
}

