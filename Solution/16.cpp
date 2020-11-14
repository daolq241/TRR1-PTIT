#include <bits/stdc++.h>

using namespace std;

void prob16 (int *a, int n) {
	int f[n];
	
	for (int i = 0; i < n; i++) {
		f[i] = a[i];
		
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				f[i] = max(f[i], f[j]+a[i]);
	}
	
	int kq = f[0];
	for (int i = 1; i < n; i++)
		kq = max(kq, f[i]);
	
	cout << kq;
}

int main (){
	int T, n;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
			
		prob16(a, n);
		cout << endl;
	}
	
	return 0;
}

