//https://codeforces.com/problemset/problem/4/A

#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if(n == 2){
		cout << "NO";
		return 0;
	}

	if(n % 2){
		cout << "NO";
	}else{
		cout << "YES";
	}
}