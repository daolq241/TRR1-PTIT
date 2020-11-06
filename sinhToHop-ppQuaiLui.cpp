#include<iostream>
using namespace std;
int n = 5, k =3, a[100];
display() {
	for(int i = 1; i<= k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
Try(int i) {
	for(int j = a[i-1] + 1; j <= n-k+i; j++) {
		a[i] = j;
		if(i == k) display();
		else Try(i+1);
	}
}
int main() {
	a[0] = 0;
	Try(1);
	return 0;
}

