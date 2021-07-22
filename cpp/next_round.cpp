//https://codeforces.com/problemset/problem/158/A

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int n, k;

    scanf("%d %d", &n, &k);

    int value, count = 0;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int kthValue = arr[k - 1];

    int i = 0;
    while (i < n)
    {
        if (arr[i] > 0 && arr[i] >= kthValue)
        {
            i++;
            continue;
        }
        else
        {
            break;
        }
    }

    cout << i;

    return 0;
}