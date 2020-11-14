#include <bits/stdc++.h>

using namespace std;

int f[1100][1100]; // f[i][j] la do dai day con chung dai nhat cua i phan tu dau cua a va j phan tu dau cua b

void prob01 (string a, string b) {
	int daiA = a.length(), daiB = b.length();
	
	a = " " + a;
	b = " " + b;
	
	for (int i = 0; i <= daiA; i++)
		for (int j = 0; j <= daiB; j++) 
			f[i][j] = 0;
	
	for (int i = 1; i <= daiA; i++)
		for (int j = 1; j <= daiB; j++)
			if (a[i] == b[j])
				f[i][j] = f[i-1][j-1] + 1;
			else
				f[i][j] = max(f[i-1][j], f[i][j-1]); 
		
	cout << f[daiA][daiB];
}

int main (){
	int T;
	string a, b;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> a >> b;
		
		prob01(a, b);
		cout << endl;
	}
	
	return 0;
}

