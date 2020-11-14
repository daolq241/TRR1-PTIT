#include <bits/stdc++.h>

using namespace std;

int f[1050][100]; // f[i, t] la do dai lon nhat cua tong day con gom i phan tu dau chia k du t

void prob04 (int *a, int n, int k) {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < k; j++)
			f[i][j] = INT_MIN;
	f[0][0] = 0;
		
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			f[i][j] = max(f[i-1][j], f[i-1][((j-a[i])%k + k)%k] + 1); // vi j-a[i] co the am nen phai lay mod k 2 lan
			
	cout << f[n][0];
}

int main (){
	int T, n, k;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> k;
		
		int a[n+1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] %= k;
		}
			
		prob04(a, n, k);
		cout << endl;
	}
	
	return 0;
}

