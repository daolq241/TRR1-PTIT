#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

int f[1100][1100];

ll giaiThua (int k) {
	ll kq = 1;
	for (int i = 2; i <= k; i++) {
		kq *= i;
		kq %= mod;
	}
	
	return kq;
}

void prob12 (int k, int n) {
	for (int i = 0; i <= k; i++)
		for (int j = i; j <= n; j++)
			if (i == 0 || j == i)
				f[i][j] = 1;
			else
				f[i][j] = (f[i-1][j-1] + f[i][j-1])%mod;
	
	cout << (f[k][n] *giaiThua(k))%mod;
}

int main (){
	int T, n, k;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> k;
		
		if (k > n)
			cout << 0;
		else
			prob12(k, n);
		cout << endl;
	}
	
	return 0;
}

