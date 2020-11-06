#include<iostream>
using namespace std;
int n = 4, a[1000];

void init(){
	for(int i =1; i <= n; i++) {
		a[i] = 0;
	}
}
void result() {
	for(int i =1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void gen() {
	int i = n;
	while(a[i] == 1) {
		a[i] = 0;
		i--;
	}
	a[i] = 1;
	
}
bool checkIsFinal() {
	for(int i =1; i <= n; i++) {
		if(a[i] == 0) return false;
	}
	return true;
}

int main() {
	init();
	while(!checkIsFinal()) {
		gen();
		result();
	}
	return 0;
}

