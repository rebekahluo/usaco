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
		// ��¼��i��Ͱ������ 
		int nai = a[i];
		
		// �½�һ������a������b�ı���
		vector<int> aa = a;
		vector<int> bb = b;
		
		// ������aa�еĵ�i��Ͱɾ��
		aa.erase(aa.begin() + i);
		
		// ������bb�����һ��Ͱ�����СΪnai
		bb.push_back(nai);
		
		// ����������
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
	//  ����ߵ�10��Ͱ��ѡһ�� 
	for (int i = 0; i < a.size(); i++)
	{
		// ��¼��i��Ͱ������ 
		int nai = a[i];
		
		// �½�һ������a������b�ı���
		vector<int> aa = a;
		vector<int> bb = b;
		
		// ������aa�еĵ�i��Ͱɾ��
		aa.erase(aa.begin() + i);
		
		// ������bb�����һ��Ͱ�����СΪnai
		bb.push_back(nai);
		
		// ����������
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

