#include <bits/stdc++.h>

using namespace std;

bool f[1100][1100]; // f[i, j] = true neu doan tu i den j co xau doi xung

void prob06 (string s) {
	int dai = s.length();
	s = " " + s;
	
	for (int i = 0; i <= dai; i++) // cac xau con do dai 1 thi luon doi xung
		f[i][i] = true;
	
	for (int j = 1; j <= dai; j++)
		for (int i = 1; i < j; i++)
			if (s[i] == s[j] && i != j-1)
				f[i][j] = f[i+1][j-1];
			else if (s[i] == s[j] && i == j-1)
				f[i][j] = true;
			else
				f[i][j] = false;
				
	int kq = 1;
	for (int i = 1; i <= dai; i++)
		for (int j = 1; j <= dai; j++)
			if (f[i][j] == true)
				kq = max(kq, j-i+1);
	
	cout << kq;
}

int main (){
	int T;
	string s;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> s;
		
		prob06(s);
		cout << endl;
	}
	
	return 0;
}

