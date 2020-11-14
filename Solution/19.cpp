#include <bits/stdc++.h>

using namespace std;

void prob19 (int n, int x, int y, int z) {
	int f[n+1]; // f[i] la thoi gian it nhat de hien thi i ki tu giong nhau len man hinh
	f[0] = 0, f[1] = x;
	
	for (int i = 2; i <= n; i++)
		if (i%2 == 0)
			f[i] = min(f[i/2]+z, f[i-1]+x);
		else
			f[i] = min(f[(i-1)/2]+x+z, min(f[i/2+1]+z+y, f[i-1]+x));
			
	cout << f[n];
}

int main (){
	int T, n, x, y, z;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> x >> y >> z;
		
		prob19(n, x, y, z);
		cout << endl;
	}
	
	return 0;
}

