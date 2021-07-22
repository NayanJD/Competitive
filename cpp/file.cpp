#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}

		cout << accumulate(v.begin(), v.end(), 0) << '\n';
	}

	return 0;
}