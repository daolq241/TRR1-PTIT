#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

ll f[150][50050]; // f[n, s] la so cac so co n chu so co tong bang s (tinh ca chu so 0 dung dau)

void prob09 (int n, int k) {
	for (int i = 1; i <= k; i++) // base case
		f[0][i] = 0;
	for (int i = 0; i <= n; i++) // base case
		f[i][0] = 1;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++) {
			f[i][j] = 0;

			for (int l = 0; l <= 9; l++)
				if (j-l >= 0) {
					f[i][j] += f[i-1][j-l];
					f[i][j] %= mod;
				}
		}
	
	ll kq = 0;
	for (int i = 1; i <= 9; i++) { // i la ki tu dau tien cua so lap duoc => bo i = 0
		kq += f[n-1][k-i];
		kq %= mod;
	}
		
	cout << kq;
}

int main (){
	int T, n, k;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> k;
		
		prob09(n, k);
		cout << endl;
	}
	
	return 0;
}

