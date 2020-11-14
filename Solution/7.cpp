#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int f[100050]; // f[i] la so cach co the di den bac thu i

void prob07 (int n, int k) {
	f[0] = 1;
	f[1] = 1;
	
	if (k == 1)
		f[2] = 1;
	else
		f[2] = 2;
		
	for (int i = 3; i <= n; i++) {
		f[i] = 0;
		
		for (int j = 1; j <= k; j++)
			if (i - j >= 0) {
				f[i] += f[i - j];
				f[i] %= mod;
			}
	}
		
	cout << f[n];
}

int main (){
	int T, n, k;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> k;
		
		prob07(n, k);
		cout << endl;
	}
	
	return 0;
}

