#include <bits/stdc++.h>

using namespace std;

int f[1050][100050]; // f[i, t] la gia tri su dung lon nhat khi chon i vat dau tien voi gioi han the tich t

void prob27 (int *a, int *c, int n, int v) {
	for (int i = 0; i <= v; i++) 
		f[0][i] = 0; // base case
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= v; j++) {
			f[i][j] = f[i-1][j]; // chon duoc vat thu i hay ko thi mac dinh f[i][j] cung se bang f[i-1][j]
			
			if (j >= a[i]) // neu chon duoc vat thu i
				f[i][j] = max(f[i][j], f[i-1][j-a[i]] + c[i]);
		}
	
	cout << f[n][v];
}

int main (){
	int T, n, v;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> v;
		
		int a[n+1], c[n+1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> c[i];
			
		prob27(a, c, n, v);
		cout << endl;
	}
	
	return 0;
}

