#include <bits/stdc++.h>
using namespace std;

int a[2000];

int main()
{
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			int ji = i * j;
			a[ji] = 1;
		}
	}
	
	int sum = 0;
	for (int i = 0; i < 2000; i++)
	{
		if (a[i] != 0)
		{
			sum++;
		}
	}
	cout << sum << endl;

	return 0;
}

