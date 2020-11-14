#include <bits/stdc++.h>

using namespace std;

void prob02 (int *a, int n) {
	int kq = 1, tmp[n];
	
	for (int i = 0; i < n; i++) {
		tmp[i] = 1;
		
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				tmp[i] = max(tmp[i], tmp[j]+1);
				
		kq = max(kq, tmp[i]);
	}
	
	cout << kq;
}

int main (){
	int n;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	prob02(a, n);
	
	return 0;
}

