#include <bits/stdc++.h>

using namespace std;

int f[150][150]; //f[i][j] la so phep min de bien i phan tu dau cua a thanh j phan tu dau cua b

void prob28 (string a, string b) {
	int daiA = a.length(), daiB = b.length();
	a = " " + a;
	b = " " + b;
	
	f[0][0] = 0; // base case
	for (int j = 1; j <= daiB; j++) // neu i = 0 (xau rong) va j != 0 thi f[i, j] = j (them j ki tu)
		f[0][j] = j;
	for (int i = 1; i <= daiA; i++) // neu i != 0 va j = 0 (xau rong) thi f[i, j] = i (xoa i ki tu)
		f[i][0] = i;
		
	for (int i = 1; i <= daiA; i++)
		for (int j = 1; j <= daiB; j++)
			if (a[i] == b[j])
				f[i][j] = f[i-1][j-1];
			else
				f[i][j] = min(f[i-1][j-1]+1, min(f[i-1][j]+1, f[i][j-1]+1)); // f[i-1][j-1]: thay the
																	   // f[i-1][j]: them
																	  // f[i][j-1]: xoa
	
	cout << f[daiA][daiB];
}

int main (){
	int T;
	string a, b;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> a >> b;
		
		prob28(a, b);
		cout << endl;
	}
	
	return 0;
}

