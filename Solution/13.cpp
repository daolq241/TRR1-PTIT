#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[10050];

void prob13 (int n) {
	int x = 2, y = 3, z = 5;
	int dem2 = 0, dem3 = 0, dem5 = 0;
	f[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		f[i] = min(x, min(y, z));
		
		if (f[i] == x) {
			dem2++;
			x = f[dem2+1] * 2;
		}
		if (f[i] == y) {
			dem3++;
			y = f[dem3+1] * 3;
		}
		if (f[i] == z) {
			dem5++;
			z = f[dem5+1] * 5;
		}
	}
	
	cout << f[n];
}

int main (){
	int T, n;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n;
		
		prob13(n);
		cout << endl;
	}
	
	return 0;
}

