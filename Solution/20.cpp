#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll chuyen (string s) {
	ll kq = s[0] - '0';
	for (int i = 1; i < s.length(); i++)
		kq = kq*10 + (s[i] - '0');
		
	return kq;
}

void prob20 (string s) {
	int dai = s.length();
	s = " " + s;
	ll kq = 0;
	
	for (int i = 1; i <= dai; i++) // so ki tu dang xet
		for (int j = 1; j <= dai-i+1; j++) { // ki tu bat dau
			string tmp = "";
			for (int k = j; k <= j+i-1; k++)
				tmp += s[k];

			kq += chuyen(tmp);
		}
	
	cout << kq;
}

int main (){
	int T;
	string s;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> s;
		
		prob20(s);
		cout << endl;
	}
	
	return 0;
}

