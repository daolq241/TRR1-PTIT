#include <bits/stdc++.h>

using namespace std;

bool f[150][25050]; // f[i, t] = true neu co cach chon bo de khoi luong la t trong so i con bo dau

int prob26 (int *a, int n, int c) {
	f[0][0] = true; // base case
	
	for (int i = 1; i <= c; i++)
		f[0][i] = false; // base case: f[0, t] = false (t > 0)
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= c; j++) {
			if (j < a[i]) // neu tong dang co < phan tu dang xet thi chi xay ra TH f[i-1, t]
				f[i][j] = f[i-1][j];
			else
				f[i][j] = f[i-1][j] || f[i-1][j-a[i]];
		}
	
	for (int i = c; i >= 0; i--)
		for (int j = 1; j <= n; j++)
			if (f[j][i] == true)
				return i;
}

int main (){
	int  c, n;
	cin >> c >> n;
		
	int a[n+1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
			
	cout << prob26(a, n, c);
	
	return 0;
}

