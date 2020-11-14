#include <bits/stdc++.h>

using namespace std;

void prob23 (int *a, int n) { // tim day tang dai nhat => kq la n - max
	int kq = 1, tmp[n];
	
	for (int i = 0; i < n; i++) {
		tmp[i] = 1;
		
		for (int j = 0; j < i; j++)
			if (a[j] <= a[i]) // chu y bai nay co phan tu bang nhau
				tmp[i] = max(tmp[i], tmp[j]+1);
				
		kq = max(kq, tmp[i]);
	}
	
	cout << n - kq;
}

int main (){
	int T, n;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		prob23(a, n);
		cout << endl;
	}
	
	return 0;
}

