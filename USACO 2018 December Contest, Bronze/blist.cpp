#include <bits/stdc++.h>
using namespace std;
int n;

int a[1000 + 10];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int s, t, b;
		cin >> s >> t >> b;
		
		for (int j = s; j <= t; j++)
		{
			a[j] += b;
		}
	}
	int maxval = -1;
	for (int i = 1; i <= 1000; i++)
	{
		maxval = max(maxval, a[i]);
	}
	cout << maxval<< endl;
	return 0;
}

