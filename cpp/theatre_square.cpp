//https://codeforces.com/problemset/problem/1/A

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int n, m, a, result;

	scanf("%lld", &n);
	scanf("%lld", &m);
	scanf("%lld", &a);

	long long length, breadth;

	length = n / a;

	breadth = m / a;

	if (n % a != 0)
	{
		length++;
	}

	if (m % a != 0)
	{
		breadth++;
	}

	result = length * breadth;

	cout << result;

	return 0;
}