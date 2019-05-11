#include <bits/stdc++.h>
using namespace std;
struct Milk
{
	int c, m;
};
Milk a[10];

void pour(int i, int j)
{
	int nai = a[i].m;
	int kong = a[j].c - a[j].m;
	
	if (nai <= kong)
	{
		a[i].m -= nai;
		a[j].m += nai;
	}
	else
	{
		a[i].m -= kong;
		a[j].m += kong;
	}
}

int main()
{
	for (int i = 1; i <= 3; i++)
	{
		cin >> a[i].c >> a[i].m;
	}
	
	int k = 0;
	
	while (1)
	{
		pour(1, 2);
		k++;
		if (k >= 100)
		{
			break;
		}
		
		pour(2, 3);
		k++;
		if (k >= 100)
		{
			break;
		}
		
		pour(3, 1);
		k++;
		if (k >= 100)
		{
			break;
		}
	}
	
	cout << a[1].m << endl;
	cout << a[2].m << endl;
	cout << a[3].m << endl;
	return 0;
}

