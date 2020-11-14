#include <bits/stdc++.h>

using namespace std;

int f[1000][1000]; // f[x][y] la tong diem it nhat khi di tu (1, 1) den (x, y)

void prob10 (int **a, int n, int m) {	
	f[1][1] = a[1][1];
	
	for (int i = 2; i <= m; i++)
		f[1][i] = f[1][i-1] + a[1][i];
	for (int i = 2; i <= n; i++)
		f[i][1] = f[i-1][1] + a[i][1];
	
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + a[i][j];
	
	cout << f[n][m];
}

int main (){
	int T, n, m;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> m;
		
		int **a = new int *[n+1];
		for (int i = 0; i <= n; i++)
			a[i] = new int[m+1];
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		
		prob10(a, n, m);
		cout << endl;
	}
	
	return 0;
}

