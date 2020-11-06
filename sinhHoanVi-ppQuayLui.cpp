#include<iostream>
using namespace std;
int n = 3, a[100];
bool unused[100];

init() {
	for(int i = 1; i <= n; i ++) {
		unused[i] = true;
	}
}
display() {
	for(int i = 1; i<= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
Try(int i) {
	for(int j = 1; j<=n; j++) {
		if(unused[j]) {
			a[i] = j;
			unused[j] = false;
			if(i == n)  display();
			else Try(i+1);
			unused[j] = true;
		}
	}
}
int main() {
	init();
	Try(1);
	return 0;
}

