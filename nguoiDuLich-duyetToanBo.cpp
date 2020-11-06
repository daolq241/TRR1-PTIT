#include<iostream>
using namespace std;
int n = 5, //so thanh pho
a[6][6] =
{	{0,  0,  0, 0,   0,  0},
	{0,  0,  3, 14, 18, 15},
 	{0,  3,  0,  4, 22, 20},
 	{0, 17,  9,  0, 16,  4},
 	{0,  6,  2,  7,  0, 12},
 	{0,  9, 15, 11,  5,  0}
},			
x[100], // hoan vi n
xopt[100],// cau hinh toi uu (duong di chuyen)
fopt = 1000; // gia tri toi uu (khoi tao duong di ngan nhat)
bool unused[100];
init() {
	for(int i = 1; i<=n; i++) {
		unused[i] = true;
	}
}
int totalValue(){
	int s = 0;
	for(int i = 1; i <=n-1; i++) {
		s += a[x[i]][x[i+1]];
	}
	s += a[x[n]][x[1]];
	return s;
}
Update(int value) {
	for (int i = 1; i <= n; i++) {
		xopt[i] = x[i];
	}
	fopt = value;
}
display() {
	for(int i = 1; i<= n; i++) {
		cout << xopt[i] << " ";
	}
	cout << xopt[1] << endl;
	cout <<"fopt = " << fopt << endl;
}
Try(int i) {
	for(int j = 1; j <=n; j++) {
		if(unused[j]){
			x[i] = j;
			unused[j] = false;
			if(i == n) {
				///
				int sumValue = totalValue();
				if (fopt > sumValue) {
					Update(sumValue);
				}
			}
			else Try(i+1);
			unused[j] = true;
		}
			
	}
}
int main() {
	init();
	Try(1);
	display(); 
	/*
	1 2 3 5 4 1
	fopt = 22
	*/
	return 0;
}

