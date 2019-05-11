#include <bits/stdc++.h>
using namespace std;

int c[3 + 10];

int a[1000 + 10];
int b[1000 + 10];
int g[1000 + 10];
int n;

int fun(int i)
{
	int sum = 0;
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	
	c[i] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		swap(c[a[i]], c[b[i]]);
		if (c[g[i]] == 1)
		{
			sum++;
		}
	}
	//cout << sum << endl;
	return sum;
}

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> g[i];
	}
	
	int maxsum = 0;
	
	for (int i = 1; i <= 3; i++)
	{
		maxsum = max(maxsum, fun(i));
	}
	
	cout << maxsum << endl;
	return 0;
}

