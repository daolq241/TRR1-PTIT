#include <bits/stdc++.h>

using namespace std;

int chuyen (string s) {
	int kq = s[0] - '0';
	for (int i = 1; i < s.length(); i++)
		kq = kq*10 + (s[i] - '0');
		
	return kq;
}

int prob29 (string m) {
	int dai = m.length();
	int f[dai+1]; // f[i] la so cach de ma hoa i ki tu dau cua m
	m = " " + m;
	
	if (m[1] == '0') // neu ki tu dau la 0 thi k co cach nao giai ma
		return 0;
	
	f[0] = 1;
	f[1] = 1; // do ki tu dau luon dam bao != '0' (vi TH = 0 da bi loai o tren)
	
	for (int i = 2; i <= dai; i++) {
		f[i] = 0;
		
		if (m[i] != '0')
			f[i] += f[i-1];
		
		if (m[i-1] != 0) {
			string tmp = "";
			tmp += m[i-1];
			tmp += m[i];
			
			if (chuyen(tmp) >= 10 && chuyen(tmp) <= 26)
				f[i] += f[i-2];
		}
	}
	
	return f[dai];
}

int main (){
	int T;
	string m;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> m;
		
		cout << prob29(m) << endl;
	}
	
	return 0;
}

