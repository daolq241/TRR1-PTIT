#include<iostream>
using namespace std;
int n = 5, a[100];
display() {
	for(int i = 1; i<= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
Try(int i) {
	for(int j = 0; j <=1; j++) {
		a[i] = j;
		if(i == n) display();
		else Try(i+1);
	}
}

int main() {
	Try(1);
	return 0;
}

