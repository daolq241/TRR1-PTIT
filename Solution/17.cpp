#include <iostream>

using namespace std;

void prob17 (int *a, int n){
	int tmp1[n]; // trai sang phai
	int tmp2[n]; // phai sang trai
	
	for (int i = 0; i < n; i++){
		tmp1[i] = a[i];
		tmp2[i] = a[i];
	}
	
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				tmp1[i] = max(tmp1[i], tmp1[j] + a[i]);
	
	for (int i = n-2; i >= 0; i--)
		for (int j = n-1; j > i; j--)
			if (a[j] < a[i])
				tmp2[i] = max(tmp2[i], tmp2[j] + a[i]);
	
	int kq = tmp1[0] + tmp2[0] - a[0];
	for (int i = 1; i < n; i++)
		kq = max(tmp1[i] +tmp2[i]-a[i], kq);
			
	cout << kq;
}

int main (){
	int T, n;
		
	cin >> T;
	
	for (int i = 1; i <= T; i++){
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
			
		prob17(a, n);
		cout << endl;
	}

	return 0;
}
