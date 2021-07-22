//https://codeforces.com/contest/1418/problem/A

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    // scanf("%d", &t);
    cin >> t;

    cout << "t:: " << t << endl;

    while (t)
    {
        long long int x, y, k;

        scanf("%lld %lld %lld", &x, &y, &k);

        // cout << "x:: " << x << endl;
        // cout << "y:: " << y << endl;
        // cout << "k:: " << k << endl;

        long long int totalSticks = k + y * k;

        long long int i = 0;

        long long totalStickConversion = 0;
        while (pow(x, i) < totalSticks)
        {
            totalStickConversion += pow(x, i);
            i++;
        }
        //code here
        long long int surplusSticks = totalSticks - pow(x, --i);

        totalStickConversion -= pow(x, i);

        long long int j = 1;

        cout << "Completing remaining stick count" << endl;
        cout << "x:: " << x << endl;
        cout << "j:: " << j << endl;
        cout << "surplusSticks:: " << surplusSticks << endl;

        while ((x - 1) * j < surplusSticks)
        {
            j++;
        }

        cout << "Done completing stick count" << endl;

        long long int result = k + totalStickConversion + j;

        cout << result << endl;

        cout << "Done completing test no " << t << endl;
        t--;
    }
}