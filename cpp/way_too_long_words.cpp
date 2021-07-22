//https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <string>
using namespace std;
    
int main()
{
    int t;

    cin >> t;

    string s;

    string::iterator begin;
    string::iterator end;

    while (t--)
    {
        cin >> s;

        if (s.length() < 11)
        {
            cout << s << endl;
        }
        else
        {
            begin = s.begin();
            end = s.end() - 1;

            cout << *begin + to_string(s.length() - 2) + *end << endl;
        }
    }
}