#include <bits/stdc++.h>

using namespace std;

bool sum[250][40050]; // mang kiem tra xay dung duoc day con co i phan tu dau tien cua a co tong bang t (sum[i, t])
						// sum[i, t] = 1 neu sum[i-1, t] = 1 hoac sum[i-1, t-a[i]] = 1
						
void prob03 (int *a, int n, int s) {
	sum[0][0] = true; // base case
	
	for (int i = 1; i <= s; i++)
		sum[0][i] = false; // base case: sum[0, t] = false (t > 0)
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= s; j++) {
			if (j < a[i]) // neu tong dang co < phan tu dang xet thi chi xay ra TH sum[i-1, t]
				sum[i][j] = sum[i-1][j];
			else
				sum[i][j] = sum[i-1][j] || sum[i-1][j-a[i]];
		}
		
	if (sum[n][s] == true)
		cout << "YES";
	else
		cout << "NO";
}

int main (){
	int T, n, s;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> s;
		
		int a[n+1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		prob03(a, n, s);
		cout << endl;
	}
	
	return 0;
}

