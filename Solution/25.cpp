#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[100]; // f[i] la so cach con ech co the di den dinh thu i

void prob25 (int n) {
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		f[i] = 0;
		
		for (int j = 1; j <= 3; j++)
			if (i - j >= 0) 
				f[i] += f[i - j];
	}
		
	cout << f[n];
}

int main (){
	int T, n;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n;
	
		prob25(n);
		cout << endl;
	}
	
	return 0;
}

