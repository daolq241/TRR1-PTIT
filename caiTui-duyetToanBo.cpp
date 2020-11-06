#include<iostream>
using namespace std;
int n = 5, b = 21, x[5]; // x[] luu cau hinh xau nhi phan( chon do xi =1, ko chon xi = 0)
int a[5] = {9, 8, 5, 3, 2},  // khoi luong
c[5] = {4, 6, 3, 5, 2}; // gia tri su dung
int xopt[5]; // Tap phuong an toi uu
int fopt = -1; // Gia tri toi uu

bool checkWeigh(){
	int s = 0;
	for(int i = 0; i <n; i++) {
		s+= a[i] * x[i];
	}
	if (s >b) return false;
	else return true;
}

int totalValue(){
	int s = 0;
	for (int i = 0; i <n; i++) {
		s+= c[i] * x[i];
	}
	return s;
}
Update(int value) {
	for (int i = 0; i < n; i++) {
		xopt[i] = x[i];
	}
	fopt = value;
}
display() {
	for(int i = 0; i< n; i++) {
		cout << xopt[i] << " ";
	}
	cout << endl;
	cout <<"fopt = " << fopt << endl;
}
Try(int i) {
	for(int j =0; j <=1; j++) {
		x[i] = j;
	
		if(i == n-1) {
			int sValue = totalValue();
			if(checkWeigh()) {
				if(fopt < sValue) {
					Update(sValue);
//					display();
				}		
			}
		}
		else Try(i+1);	
	}
}


int main() {
	Try(0);
	display();
	/*
	0 1 1 1 1
	fopt = 16
	*/
	return 0;
}

