#include <iostream>

using namespace std;

void prob22 (int *a, int n){
	int inclu = a[0]; // tong lon nhat bao gom phan tu hien tai
	int exclu = 0; // tong lon nhat khong bao gom phan tu hien tai. Chi co exclu duoc xet den do 2 ptu k lien ke
	int tmp; // gia tri trung gian luu tru inclu
	
	for (int i = 1; i < n; i++){
		tmp = inclu;
		inclu = exclu + a[i];
		exclu = max(exclu, tmp);
	}
	
	cout << max(exclu, inclu);
}

int main(){
	int T, n;
	
	cin >> T; 
	for (int t = 1; t <= T; t++){
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		prob22(a, n);
		cout << endl;
	}
	
	return 0;
}
