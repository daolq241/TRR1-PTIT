#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int f[1100][1100];

void prob05 (int k, int n) {
	for (int i = 0; i <= k; i++)
		for (int j = i; j <= n; j++)
			if (i == 0 || j == i)
				f[i][j] = 1;
			else
				f[i][j] = (f[i-1][j-1] + f[i][j-1])%mod;
	
	cout << f[k][n];
}

int main (){
	int T, n, k;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> k;
		
		prob05(k, n);
		cout << endl;
	}
	
	return 0;
}

