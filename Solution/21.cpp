#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

void prob21 (int *a, int n, int k) {
	ll f[k+1]; // f[i] la so cach phan tich i
	f[0] = 1; // base case
	
	for (int i = 1; i <= k; i++) {
		f[i] = 0;
		
		for (int j = 0; j < n; j++)
			if (i - a[j] >= 0) {
				f[i] += f[i-a[j]];
				f[i] %= mod;
			}
	}
				
	cout << f[k];
}

int main (){
	int T, n, k;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> k;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		prob21(a, n, k);
		cout << endl;
	}
	
	return 0;
}

