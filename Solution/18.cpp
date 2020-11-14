#include <bits/stdc++.h>

using namespace std;

struct cap {
	int first;
	int second;
};

bool comp (cap x, cap y) {
	return x.first < y.first;
}

void prob18 (cap *a, int n) {
	sort(a, a+n, comp);
	
	int f[n];

	for (int i = 0; i < n; i++) {
		f[i] = 1;
		
		for (int j = 0; j < i; j++)
			if (a[j].second < a[i].first)
				f[i] = max(f[i], f[j]+1);
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
		
		cap a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i].first >> a[i].second;
			
		prob18(a, n);
		cout << endl;
	}
	
	return 0;
}

