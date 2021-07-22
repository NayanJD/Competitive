//https://codeforces.com/problemset/problem/118/A

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{

    string input;

    cin >> input;

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    string result = "";

    for (auto i = input.begin(); i != input.end(); i++)
    {
        if (vowels.find(*i) == vowels.end())
        {
            result = result + "." + *i;
        }
    }

    cout << result;
}