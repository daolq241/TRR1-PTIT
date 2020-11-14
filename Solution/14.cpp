#include <bits/stdc++.h>

using namespace std;

int f[150][150]; // f[i][j] la do dai day con chung dai nhat cua i phan tu dau cua a va j phan tu dau cua b

void prob14 (string a, int n) { // quy ve bai toan tim xau chung dai nhat cua a voi a
	a = " " + a;
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) 
			f[i][j] = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == a[j] && i != j)
				f[i][j] = f[i-1][j-1] + 1;
			else
				f[i][j] = max(f[i-1][j], f[i][j-1]); 
		
	cout << f[n][n];
}

int main (){
	int T, n;
	string s;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> s;
		
		prob14(s, n);
		cout << endl;
	}
	
	return 0;
}

