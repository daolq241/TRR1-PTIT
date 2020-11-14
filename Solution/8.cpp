#include <bits/stdc++.h>

using namespace std;

void prob08 (int **a, int n, int m){
	int tmp[n][m]; // ma tran phu dung de QHD
	for (int i = 0; i < m; i++) // copy hang dau
		tmp[0][i] = a[0][i];
	for (int i = 0; i < n; i++) // copy cot dau
		tmp[i][0] = a[i][0];
		
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (a[i][j] == 1)
				tmp[i][j] = min(tmp[i][j-1], min(tmp[i-1][j], tmp[i-1][j-1])) + 1;
			else
				tmp[i][j] = 0;
	
	int Max = tmp[0][0]; // tim min cua ma tran phu
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Max = max(Max, tmp[i][j]);
			
	cout << Max;
}

int main (){
	int T, n, m;
	
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> m;
		
		int **a = new int *[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[m];
			
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
				
		prob08(a, n, m);
		cout << endl;
	}
	
	return 0;
}

