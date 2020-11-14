#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[30][30]; // f[x][y] la so cach di chuyen tu (x, y) ve (0, 0)

void prob24 (int n, int m) {	
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		f[i][0] = 1;
	for (int i = 1; i <= m; i++)
		f[0][i] = 1;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[j-1][i] + f[j][i-1];
	
	cout << f[n][m];
}

int main (){
	int T, n, m;

	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> m;
	
		prob24(n, m);
		cout << endl;
	}
	
	return 0;
}

