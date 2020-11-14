#include <bits/stdc++.h>

using namespace std;

int f[110][110][110]; // f[i][j] la do dai day con chung dai nhat cua i phan tu dau cua a va j phan tu dau cua b

void prob15 (string a, string b, string c) {
	int daiA = a.length(), daiB = b.length(), daiC = c.length();
	
	a = " " + a;
	b = " " + b;
	c = " " + c;
	
	for (int i = 0; i <= daiA; i++)
		for (int j = 0; j <= daiB; j++)
			for (int k = 0; k <= daiC; k++)
				f[i][j][k] = 0;
	
	for (int i = 1; i <= daiA; i++)
		for (int j = 1; j <= daiB; j++)
			for (int k = 1; k <= daiC; k++)
				if (a[i] == b[j] && b[j] == c[k])
					f[i][j][k] = f[i-1][j-1][k-1] + 1;
				else
					f[i][j][k] = max(f[i-1][j][k], max(f[i][j-1][k], f[i][j][k-1])); 
		
	cout << f[daiA][daiB][daiC];
}

int main (){
	int T, daiA, daiB, daiC;
	string a, b, c;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> daiA >> daiB >> daiC;
		cin >> a >> b >> c;
		
		prob15(a, b, c);
		cout << endl;
	}
	
	return 0;
}

