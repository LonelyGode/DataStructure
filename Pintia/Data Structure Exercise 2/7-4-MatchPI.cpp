#include <bits/stdc++.h> 
using namespace std;
int main() {
	char a[1000000], b[1000000];
	int c[1000000];
	scanf("%s %s", a, b);
	int n = strlen(a), m = strlen(b), sum = 0;
	for (int i = 0; i<n - m + 1; i++)
	{
		if (a[i] == b[0] && a[i + m - 1] == b[m - 1])
		{
			c[sum++] = i;
		}
	}

	if (m == 1 && sum>0)
	{
		printf("%d", c[0]);
		return 0;
	}
	for (int i = 1; i<m; i++)
	{
		int p = 0;
		for (int j = 0; j<sum; j++)
		{
			if (b[i] == a[c[j] + 1])
			{

				c[p++] = c[j] + 1;
			}
		}
		sum = p;
		if (p == 0)
		{
			break;
		}
		if (i == m - 1)
		{
			printf("%d", c[0] - i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
