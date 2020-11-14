#include <bits/stdc++.h>

using namespace std;

void prob30 (int n) {
	vector <int> scp; // danh sach cac so chinh phuong <= n
	for (int i = 1; i <= sqrt(n); i++)
		scp.push_back(i*i);

	int f[n+1]; // f[i] la so luong so it nhat de phan tich i
	f[0] = 0; // base case
	f[1] = 1;
	f[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		f[i] = i;  // truong hop xau nhat la i so 1
		
		for (int j = 0; j < scp.size(); j++)
			if (i - scp[j] >= 0)
				f[i] = min(f[i], f[i-scp[j]] + 1);
			else
				break;
	}
	
	cout << f[n];
}

int main (){
	int T, n;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n;
		
		prob30(n);
		cout << endl;
	}
	
	return 0;
}

